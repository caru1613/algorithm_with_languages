/*** user.cpp ***/
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
using pii = pair<int, int>;

priority_queue<pii> down[10];							// {-point, id} 큰게 top()
priority_queue<pii, vector<pii>, greater<>> up[10];		// {-point, id} 작은게 top()

int carCnt;												// 칸 개수
int car[100003];										// car[uID] = uID 탑승객의 칸
int point[100003];										// point[uID] = uID 회원의 포인트

vector<int> joblist[1003];								// joblist[jobID] = { jobID 직업의 탑승객 리스트 }

void push(int x) {
	up[car[x]].push({ -point[x], x });
	down[car[x]].push({ -point[x], x });
}

void init(int N, int M, int J, int Point[], int JobID[])
{
	carCnt = N / M;
	for (int i = 0; i < J; i++) joblist[i].clear();
	for (int i = 0; i < carCnt; i++) up[i] = {}, down[i] = {};

	for (int i = 0; i < N; i++) {
		point[i] = Point[i];
		joblist[JobID[i]].push_back(i);

		car[i] = i / M;
		push(i);
	}
}

void destroy() {}

int update(int uID, int Point)
{
	point[uID] += Point;
	push(uID);
	return point[uID];
}

int updateByJob(int JobID, int Point)
{
	int ret = 0;
	for (int x : joblist[JobID]) {
		point[x] += Point;
		push(x);
		ret += point[x];
	}
	return ret;
}

template<typename T>
void popNum(T& pq, int cID, int num, vector<int>&v) {	// pq에서 cID 칸 탑승객
	while (num) {										// num명을 뽑아 v에 저장
		int p = -pq.top().first;
		int id = pq.top().second;
		pq.pop();
		if (point[id] != p) continue;				// 최신포인트인지
		if (car[id] != cID) continue;				// 최신칸인지
		if (v.size() && v.back() == id) continue;	// 중복인지
		v.push_back(id);
		num--;
	}
}

int move(int num)
{
	vector<int> a[10];	// a[cID] = { cID 칸으로 옮겨지는 탑승객 uID 리스트 }
	int ret = 0;
	for (int i = 1; i < carCnt; i++) {	// 이동하는 탑승객 a에 저장, pq에서 제거
		popNum(down[i - 1], i - 1, num, a[i]);
		popNum(up[i], i, num, a[i - 1]);
	}
	for (int i = 0; i < carCnt; i++) {	// 이동하는 칸으로 pq에 등록
		for (int x : a[i]) {
			car[x] = i;
			push(x);
			ret += point[x];
		}
	}
	return ret;
} 
 
/*** main. cpp ***/
 
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_UPDATE 300
#define CMD_UPDATE_JOB 400
#define CMD_MOVE 500
 
/////////////////////////////////////////////////////////////////////////
extern void init(int N, int M, int J, int Point[], int JobID[]);
extern void destroy();
extern int update(int uID, int Point);
extern int updateByJob(int JobID, int Point);
extern int move(int num);
/////////////////////////////////////////////////////////////////////////
#define MAX_N 100000
 
static int Point[MAX_N];
static int JobID[MAX_N];
 
static int run()
{
    int isOK = 0;
    int N;
    int cmd, result, check;
 
    int mN, mM, mJ;
    int mID, mJobID;
    int mPoint, mNum;
 
    scanf("%d", &N);
 
    for (int c = 0; c < N; ++c)
    {
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            scanf("%d %d %d", &mN, &mM, &mJ);
            for (int i = 0; i < mN; i++) scanf("%d", &Point[i]);
            for (int i = 0; i < mN; i++) scanf("%d", &JobID[i]);
            init(mN, mM, mJ, Point, JobID);
            isOK = 1;
            break;
 
        case CMD_UPDATE:
            scanf("%d %d", &mID, &mPoint);
            result = update(mID, mPoint);
            scanf("%d", &check);
            if (result != check)
                isOK = 0;
            break;
 
        case CMD_UPDATE_JOB:
            scanf("%d %d", &mJobID, &mPoint);
            result = updateByJob(mJobID, mPoint);
            scanf("%d", &check);
            if (result != check)
                isOK = 0;
            break;
 
        case CMD_MOVE:
            scanf("%d", &mNum);
            result = move(mNum);
            scanf("%d", &check);
            if (result != check)
                isOK = 0;
            break;
 
        default:
            isOK = 0;
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

