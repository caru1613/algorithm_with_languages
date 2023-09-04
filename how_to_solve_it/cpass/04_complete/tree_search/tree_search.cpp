
#include <cstring> 
#include <queue> 
#include <vector> 

using namespace ::std;

const int LM = 351;
const int IDLM = 100000;

int curTime; // 현재 시각
int copPos; // 경찰의 현재 위치
int nextTown[LM][LM]; // 목적지를 향하여 이동할 때, 1시간 뒤 위치 테이블 
int cancelFlag[IDLM]; // 취소 표시
int visited[LM], vn;

struct Event { ;
    int tick; // 사건이 일어난 시각 
    int id; // 사건 id
    int town; // 목적도시
    int prior; // 처리 우선순위
    bool operator <(const Event&t) const { // 1. 처리우선순위 desc, 2. 일어난 시각 asc
        return (prior != t.prior ? prior < t.prior : tick > t.tick); 
    }
};

priority_queue<Event> pq; // 우선순위 큐 
vector<int> adj[LM]; // 인접 배열
                     //
void dfs(int src, int town, int dest) { // nextTown[][]구하기 방법 1 : dfs를 이용 
    if (visited[dest] == vn) 
        return;

    visited[dest] = vn;
    nextTown[src][dest] = town;
    for (auto d : adj[dest])
        dfs(src, town, d);
}

void bfs(int src, int town, int dest) { // nextTown[][]구하기 방법 2 : bfs를 이용 
    queue<int> que;
    visited[town] = vn;
    que.push(town);
    while (!que.empty()) {
        dest = que.front();
        que.pop();
        nextTown[src][dest] = town;
        for (auto d : adj[dest]) {
            if (visited[d] != vn) { 
                visited[d] = vn; 
                que.push(d);
            } 
        }
    } 
}

void init(int N, int parent[]) {
    curTime = 0;
    copPos = 0;
    memset(cancelFlag, 0, sizeof(cancelFlag)); 
    pq = {};
    // 인접배열 만들기
    for (int i = 0; i < LM; ++i) adj[i].clear(); 
        for (int i = 1; i < N; i++) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    // nextTown[][]만들기
    for (int s = 0; s < N; s++) {
        visited[s] = ++vn;
        //for (auto m : adj[s]) dfs(s, m, m); // 방법 1 
        for (auto m : adj[s]) bfs(s, m, m); // 방법 2
    } 
}

void update(int endTime) {
    for (; curTime < endTime; curTime++) {
        // 1. 최 우선순위 구하기
        while (!pq.empty() && cancelFlag[pq.top().id])
            pq.pop();
        if (pq.empty()) { // 최 우선순위가 없는 경우
            curTime = endTime;
            break; 
        }
        // 2. 최 우선순위가 있는 경우
        int destTown = pq.top().town;
        if (destTown == copPos) // 목적지 도착후 1시간 지남.
            pq.pop();
        else // 다음 마을로 : 다음에 확인할때는 1시간이 지난 상태가 됨.
            copPos = nextTown[copPos][destTown];
    } 
}

void occur(int timeStamp, int caseID, int townNum, int prior) { 
    update(timeStamp);
    pq.push({ timeStamp, caseID, townNum, prior }); // 새로운 사건 발생
}

void cancel(int timeStamp, int caseID) { 
    update(timeStamp);
    cancelFlag[caseID] = 1; // 사건 처리 취소.
}

int position(int timeStamp) { 
    update(timeStamp);
    return copPos; // 현재 경찰의 위치
}

/// *** main.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define INIT     1
#define OCCUR    2
#define CANCEL   3
#define POSITION 4

extern void init(int N, int parent[]);
extern void occur(int timeStamp, int caseID, int townNum, int prior);
extern void cancel(int timeStamp, int caseID);
extern int position(int timeStamp);

static int parent[350];

static bool run()
{
    int queryCnt;
    int N, timeStamp, caseID, townNum, prior;
    int userAns, ans;
    bool isCorrect = false;

    scanf("%d", &queryCnt);

    for (int i = 0; i < queryCnt; ++i)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case INIT:
            scanf("%d", &N);
            for (int j = 0; j < N; j++)
                scanf("%d", &parent[j]);
            init(N, parent);
            isCorrect = true;
            break;
        case OCCUR:
            scanf("%d %d %d %d", &timeStamp, &caseID, &townNum, &prior);
            occur(timeStamp, caseID, townNum, prior);
            break;
        case CANCEL:
            scanf("%d %d", &timeStamp, &caseID);
            cancel(timeStamp, caseID);
            break;
        case POSITION:
            scanf("%d", &timeStamp);
            userAns = position(timeStamp);
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

    int T, SUCCESS;
    scanf("%d %d", &T, &SUCCESS);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? SUCCESS : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
