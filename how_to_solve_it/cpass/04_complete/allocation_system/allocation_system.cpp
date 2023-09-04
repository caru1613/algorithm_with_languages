#include<set>
#include<unordered_map>

using namespace std;
using pii = pair<int, int>;

unordered_map<int, int> used;                       // used[s] = e
set<pii> unused;                                    // unused : {size, s}
unordered_map<int, set<pii>::iterator> sit, eit;    // sit[s] = unused it , eit[e] = unused it

void init(int N) {
    used.clear();
    unused.clear();
    sit.clear();
    eit.clear();
    sit[0] = eit[N] = unused.insert({ N, 0 }).first;    // N 크기의 빈 공간 추가. 
}

int allocate(int size) {
    auto it = unused.lower_bound({ size, 0 });          // {size, 0} 보다 크거나 같은 가장 작은 it 선택.
    if (it == unused.end()) return -1;                  // 없으면  -1

    int s = it->second, e = it->second + size;          // 할당할  [s:e)
    int remainSize = it->first - size;                  // 할당 후 남은 빈공간의 크기.

    used[s] = e;                                        // 사용 상태로 저장.

    unused.erase(it);                                   // 미사용 상태의 기록 삭제.
    sit.erase(s);
    eit.erase(e);

    if (remainSize)                                     // 빈공간이 남아 있다면 등록.
        sit[e] = eit[e + remainSize] = unused.insert({ remainSize, e }).first;

    return s;
}

int deallocate(int start) {
    if (!used.count(start)) return -1;      // start가 할당된 공간의 맨 앞 번호가 아닌 경우.

    int s = start, e = used[start];
    int ret = e - s;
    used.erase(s);

    if (eit.count(s)) {                     // 왼쪽 공간의 빈 공간인 경우.
        auto it = eit[s];
        sit.erase(it->second);
        eit.erase(s);
        s = it->second;
        unused.erase(it);
    }
    if (sit.count(e)) {                     // 오른쪽 공간이 빈 공간인 경우.
        auto it = sit[e];
        sit.erase(e);
        eit.erase(it->first + e);
        e += it->first;
        unused.erase(it);
    }
    sit[s] = eit[e] = unused.insert({ e - s,s }).first;

    return ret;
}

/*** main.cpp ***/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern int allocate(int size);
extern int deallocate(int start);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ALLOCATE 2
#define CMD_DEALLOCATE 3

static bool run() {
    int q;
    scanf("%d", &q);

    int n, start, size;
    int cmd, ans, ret = 0;
    bool okay = false;

    for (int i = 0; i < q; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
        case CMD_INIT:
            scanf("%d", &n);
            init(n);
            okay = true;
            break;
        case CMD_ALLOCATE:
            scanf("%d %d", &size, &ans);
            ret = allocate(size);
            if (ans != ret)
                okay = false;
            break;
        case CMD_DEALLOCATE:
            scanf("%d %d", &start, &ans);
            ret = deallocate(start);
            if (ans != ret)
                okay = false;
            break;
        default:
            okay = false;
            break;
        }
    }
    return okay;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++) {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
