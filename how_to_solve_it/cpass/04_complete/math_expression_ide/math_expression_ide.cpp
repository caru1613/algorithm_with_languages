/* user.cpp */
#include<list>
#include<stack>
#include<string>
#include<unordered_map>
#include<string.h>
using namespace std;

struct Cmd {
    string str;             // 수식 우변, 예외 처리를 위해 수식 가장 바깥에 ( 수식 ) 를 씌어서 저장
    int variable;           // 수식을 통해 변경되는 변수 이름(A:0, B:1, ..., Z:25)
    int orgValue;           // 수식을 통해 변경되는 변수의 기존 값
};
list<Cmd> cmd;
list<Cmd>::iterator cur;    // cursor가 위치한 cmd 위치
int value[26];              // value[A:0, B:1, ..., Z:25] = 현재 값
int line;                   // 현재 라인 번호

void init() {
    cmd.clear();
    cur = cmd.begin();
    line = 1;
    memset(value, 0, sizeof(value));
}

void destroy()
{
}

int add(char command[])
{
    cur = cmd.insert(cur, { '(' + string(command+2) + ')', command[0]-'A' }); // 현재 cursor 위치에 수식을 등록하고 cursor를 등록한 위치로 이동
    return line;
}

int sN, oN;     // 수를 담는 스택 원소 개수, 연산자 담는 스택 원소 개수
int su[100];    // 수를 담는 스택
char op[100];   // 연산자를 담는 스택

void calc() {
    int&l = su[sN - 1], r = su[sN];             // 연산자 앞쪽 수, 연산자 뒤쪽 수
    if (op[oN] == '*') l = (l * r) % 10000;
    if (op[oN] == '/') l = r ? l / r : 0;
    if (op[oN] == '+') l = (l + r) % 10000;
    if (op[oN] == '-') l = max(0, l - r);
    sN--, oN--;
}

int getValue(string&str) {
    sN = oN = 0;
    for (char ch : str) {
        if (ch == ')') {                                        // ')' 인 경우
            while (op[oN] != '(') calc();                       // 괄호 시작까지 계산
            oN--;
        }
        else if (ch == '(') op[++oN] = '(';
        else if (ch == '*' || ch == '/') {                      // '*', '/' 인 경우
            if (op[oN] == '*' || op[oN] == '/') calc();         // 앞쪽 연산이 '*', '/' 인 경우 앞쪽 연산 수행
            op[++oN] = ch;
        }
        else if (ch == '+' || ch == '-') {                      // '+', '-' 인 경우,
            while (op[oN] != '(') calc();                       // 앞쪽 연산이 '*', '/', '+', '-' 인 경우 앞쪽 연산 수행
            op[++oN] = ch;
        }
        else if (ch >= 'A') su[++sN] = value[ch - 'A'];         // 변수인 경우

        else su[++sN] = ch - '0';                               // 숫자인 경우
    }
    return su[1];
}

int move(int pos)
{
    if (pos < 0)
        while (pos++ && cur != cmd.begin()) {           // 라인 수행 취소
            --cur;
            line--;
            value[cur->variable] = cur->orgValue;
        }
    else
        while (pos-- && cur != cmd.end()) {             // 라인 수행
            cur->orgValue = value[cur->variable];
            value[cur->variable] = getValue(cur->str);
            ++cur;
            line++;
        }
    return line;
}

void erase()
{
    if (cur != cmd.end()) cur = cmd.erase(cur);         // 라인 삭제
}

int get(char variable)
{
    return value[variable - 'A'];
} 
 
/* main.cpp */
 
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_MOVE 300
#define CMD_ERASE 400
#define CMD_GET 500
 
extern void init();
extern void destroy();
extern int add(char command[]);
extern int move(int pos);
extern void erase();
extern int get(char variable);
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
 
static int run()
{
    int isOK = 1;
 
    int N;
    scanf("%d", &N);
 
    int cmd;
    int result;
    int check;
 
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            break;
        case CMD_ADD:
            char command[100];
            scanf("%s", command);
            result = add(command);
            scanf("%d", &check);
            if (result != check) {
                isOK = 0;
            }
            break;
        case CMD_MOVE:
            int pos;
            scanf("%d", &pos);
            result = move(pos);
            scanf("%d", &check);
            if (result != check) {
                isOK = 0;
            }
            break;
        case CMD_ERASE:
            erase();
            break;
        case CMD_GET:
            char variable[2];
            scanf("%s", variable);
            result = get(variable[0]);
            scanf("%d", &check);
            if (result != check) {
                isOK = 0;
            }
            break;
        default:
            break;
        }
    }
    destroy();
    return isOK;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);
 
    for (int tc = 1; tc <= T; tc++)
    {
        if (run()) printf("#%d %d\n", tc, MARK);
        else printf("#%d %d\n", tc, 0);
    }
    return 0;
}
