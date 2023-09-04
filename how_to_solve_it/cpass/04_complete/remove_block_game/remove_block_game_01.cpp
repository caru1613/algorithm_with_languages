/*** user.cpp ***/
/*
* 연속된 block을 하나의 노드로 관리		: linked list, 1)시간 2)열오름차순 관리
* 지워야하는 열을 낱개로 배열로 관리    : removed[col] = rcnt : 지워진 경우
*/
#include<list>
using namespace std;

int R, C, total;
struct Data { int t, s, e; };
list<Data> block;

void init(int r, int c) {
	R = r, C = c, total = 0;
	block.clear();
}

void update(int timestamp) {
	while (block.size()) {
		auto it = block.begin();			// 가장 먼저 들어온 블록 선택
		if (timestamp - it->t < R) break;	// 아직 맵에서 안벗어난 경우 종료

		total -= it->e - it->s + 1;			// 개수 업데이트 후,
		block.erase(it);					// 맵에서 제거
	}
}

int dropBlocks(int timestamp, int col, int len) {
	update(timestamp);
	block.push_back({ timestamp, col, col + len - 1 });
	total += len;
	return total;
}

int removed[10003], rcnt;   // removed[col] = rcnt : 지워진 열
int removeBlocks(int timestamp) {
    rcnt++;
    update(timestamp);

    for (auto it = block.begin(); it != block.end();) {
        int t = it->t, s = it->s, e = it->e;
        it = block.erase(it);

        for (int i = s; i <= e;) {
            if (removed[i] == rcnt) {   // 이미 지워진 열, 새롭게 노드 생성
                int start = i;
                while (i <= e && removed[i] == rcnt) i++;
                block.insert(it, { t,start,i - 1 });
            }
            else {                      // 안지워진 열
                removed[i++] = rcnt;
                total--;
            }
        }
    }
    return total;
} 
 
/*** main.cpp ***/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
void init(int R, int C);
int dropBlocks(int timestamp, int col, int len);
int removeBlocks(int timestamp);
 
#define CMD_INIT 100
#define CMD_DROP 200
#define CMD_REMOVE 300
 
static bool run()
{
    int query_num;
    scanf("%d", &query_num);
 
    int ret, ans;
    bool ok = false;
 
    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
 
        if (query == CMD_INIT)
        {
            int R, C;
            scanf("%d %d", &R, &C);
            init(R, C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int timestamp, col, len;
            scanf("%d %d %d", &timestamp, &col, &len);
            ret = dropBlocks(timestamp, col, len);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_REMOVE)
        {
            int timestamp;
            scanf("%d", &timestamp);
            ret = removeBlocks(timestamp);
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
 
    }
    return ok;
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

