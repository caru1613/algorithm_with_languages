// *** main.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
extern int init(int N, int sCity[], int eCity[], int mCost[]);
extern void add(int sCity, int eCity, int mCost);
extern int cost(int mHub);
 
/////////////////////////////////////////////////////////////////////////
 
#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3
 
static bool run() {
    int q;
    scanf("%d", &q);
 
    int n;
    int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
    int sCity, eCity, mCost, mHub;
    int cmd, ans, ret = 0;
    bool okay = false;
 
    for (int i = 0; i < q; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
        case CMD_INIT:
            okay = true;
            scanf("%d", &n);
            for (int j = 0; j < n; ++j) {
                scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
            }
            scanf("%d", &ans);
            ret = init(n, sCityArr, eCityArr, mCostArr);
            if (ans != ret)
                okay = false;
            break;
        case CMD_ADD:
            scanf("%d %d %d", &sCity, &eCity, &mCost);
            add(sCity, eCity, mCost);
            break;
        case CMD_COST:
            scanf("%d %d", &mHub, &ans);
            ret = cost(mHub);
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
 
// *** user.cpp ***

/*
* Floyd-Warshall : O(V^3)
* V:노드수 , E:간선수
*/
#include<algorithm>
#include<unordered_map>
using namespace std;
const int INF = 1e9;

int n;
unordered_map<int, int> idmap;  // idmap[city] = id(0~)
int dist[603][603];

int getid(int x) {
    /* 이전에 이미 나온 경우*/
    if (idmap.count(x)) return idmap[x];

    /* 처음나온 경우 */
    for (int i = 0; i < n; i++) dist[n][i] = dist[i][n] = INF; // 초기화
    return idmap[x] = n++;      //  0부터 id 부여
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    idmap.clear();
    n = 0;

    for (int i = 0; i < N; i++)
        dist[getid(sCity[i])][getid(eCity[i])] = mCost[i];

    for (int k = 0; k < n; k++)             // k : 거치는 노드
        for (int i = 0; i < n; i++)         // i : 시작 노드
            for (int j = 0; j < n; j++)     // j : 도착 노드
                // min(i->j, i->k->j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return n;
}

void add(int sCity, int eCity, int mCost) {
    int s = getid(sCity), e = getid(eCity);

    if (dist[s][e] > mCost) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                // min(i->j, i->s->e->j)
                dist[i][j] = min(dist[i][j], dist[i][s] + mCost + dist[e][j]);
    }
}

int cost(int mHub) {
    mHub = getid(mHub);
    int ret = 0;
    for (int i = 0; i < n; i++) ret += dist[i][mHub] + dist[mHub][i];
    return ret;
}
