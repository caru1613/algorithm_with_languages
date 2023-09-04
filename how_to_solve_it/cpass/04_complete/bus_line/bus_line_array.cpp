/*** user.cpp ***/
 
#include<queue>
using namespace std;
using pii = pair<int, int>;

pii adj[40003][5];  // adj[id][line] = { prev, next }
int lineStart[5], n;

void init(int N, int start[5], int end[5])
{
    n = N;
    for (int i = 0; i < N; i++) for (int j = 0; j < 5; j++)
        adj[i][j] = { -1,-1 };

    for (int i = 0; i < 5; i++) {
        lineStart[i] = start[i];
        adj[start[i]][i].second = end[i];
        adj[end[i]][i].first = start[i];
    }
}

void append(int line, int prev, int cur)
{
    int next = adj[prev][line].second;
    adj[cur][line] = { prev, next };
    adj[prev][line].second = cur;
    adj[next][line].first = cur;
}


queue<pii> q;
int tick[40003][5], dest;

bool existLine(int x, int line) { return adj[x][line] != pii(-1, -1); }

bool push(int x, int line, int cnt) {
    if (x == -1 || !existLine(x, line) || tick[x][line] <= cnt) return 0;
    tick[x][line] = cnt;
    q.push({ x, line });
    return x == dest;
}

int minTime(int start, int end)
{
    if (start == end) return 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) tick[i][j] = 5e4;
    q = {};
    dest = end;
    for (int i = 0; i < 5; i++)
        push(start, i, 0);

    while (q.size()) {
        int x = q.front().first;
        int line = q.front().second;
        q.pop();

        int newTick = tick[x][line] + 1;
        if (push(adj[x][line].first, line, newTick)) return newTick;
        if (push(adj[x][line].second, line, newTick)) return newTick;

        for (int i = 0; i < 5; i++)
            if (line != i) push(x, i, newTick);
    }

    return -1;
}


int minTransfer(int start, int end)
{
    queue<int> q;
    int cnt[5] = { 5,5,5,5,5 };

    for (int i = 0; i < 5; i++) {
        if (existLine(start, i)) {
            q.push(i);
            cnt[i] = 0;
        }
    }

    while (q.size()) {
        int line = q.front();
        q.pop();
        for (int x = lineStart[line]; x != -1; x = adj[x][line].second) {
            if (x == end) return cnt[line];
            for (int i = 0; i < 5; i++) {
                if (cnt[i] <= cnt[line]+1 || !existLine(x, i)) continue;
                q.push(i);
                cnt[i] = cnt[line] + 1;
            }
        }
    }

    return -1;
} 

/*** main.cpp ***/
 
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
#define CMD_INIT 1
#define CMD_APPEND 2
#define CMD_MIN_TIME 3
#define CMD_MIN_TRANSFER 4
 
extern void init(int N, int lastBusStop1[], int lastBusStop2[]);
extern void append(int mLine, int prevBusStop, int nextBusStop);
extern int minTime(int start, int end);
extern int minTransfer(int start, int end);
 
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
 
const int numberOfLine = 5;
static int lastBusStop1[numberOfLine];
static int lastBusStop2[numberOfLine];
 
static bool run()
{
    int numQuery;
 
    int N;
    int line, prevBusStop, nextBusStop;
    int start_id, end_id;
 
    int userAns, ans;
 
    bool isCorrect = false;
 
    scanf("%d", &numQuery);
 
    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
 
        switch (cmd)
        {
        case CMD_INIT:
            scanf("%d", &N);
            for (int j = 0; j < numberOfLine; j++)
                scanf("%d", &lastBusStop1[j]);
            for (int j = 0; j < numberOfLine; j++)
                scanf("%d", &lastBusStop2[j]);
            init(N, lastBusStop1, lastBusStop2);
            isCorrect = true;
            break;
        case CMD_APPEND:
            scanf("%d %d %d", &line, &prevBusStop, &nextBusStop);
            append(line, prevBusStop, nextBusStop);
            break;
        case CMD_MIN_TIME:
            scanf("%d %d", &start_id, &end_id);
            userAns = minTime(start_id, end_id);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_MIN_TRANSFER:
            scanf("%d %d", &start_id, &end_id);
            userAns = minTransfer(start_id, end_id);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }
    return isCorrect;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
 
    int T, MARK;
    scanf("%d %d", &T, &MARK);
 
    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
 
    return 0;
}

