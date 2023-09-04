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
* Dijkstra(linear search) : O(V^2 + E)
* V:노드수 , E:간선수
*/
#include<vector>
#include<unordered_map>
using namespace std;
using pii = pair<int, int>;

int n;
unordered_map<int, int> idmap;
vector<pii> adj[603], rAdj[603];    // adj[x] = { {y,cost} list }

int getid(int x) {
    if (idmap.count(x)) return idmap[x];
    return idmap[x] = n++;                  //  0부터 id 부여
}

void add(int sCity, int eCity, int mCost) {
    int s = getid(sCity), e = getid(eCity);
    adj[s].push_back({ e, mCost });
    rAdj[e].push_back({ s, mCost });
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    for (int i = 0; i < n; i++) adj[i].clear(), rAdj[i].clear();
    idmap.clear();
    n = 0;

    for (int i = 0; i < N; i++)
        add(sCity[i], eCity[i], mCost[i]);

    return n;
}

bool visited[603];
int dist[603];

int getMin() {
    int minDist = 1e9, x;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (minDist > dist[i])
            minDist = dist[i], x = i;
    }
    return x;
}

int dijkstra(int start, vector<pii>v[]) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        dist[i] = 1e9, visited[i] = 0;      // 1e9 = (double)1,000,000,000
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int cur = getMin();
        visited[cur] = 1;
        ret += dist[cur];
        for (pii p : v[cur]) {
            int next = p.first, cost = p.second;
            dist[next] = min(dist[next], dist[cur] + cost);
        }
    }

    return ret;
}

int cost(int mHub) {
    mHub = getid(mHub);
    return dijkstra(mHub, adj) + dijkstra(mHub, rAdj);
}
