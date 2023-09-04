/*** user.cpp ***/
#include<algorithm>
#include<vector>
using namespace std;
extern int query(int M, int sub[], int opt);

const int N = 1000;
int sub[N];		// query 호출용
int minv[4];	// rank가 0,1,2,3 인 id들
vector<int> v;	// rank가 안정해진 id들

int find(int x) {
	/* parametric search (binary search) */
	int n;
	int s = 0, e = v.size() - 1, mid;
	while (e - s > 4) {						// [s:e] 5개 이하될때까지
		mid = (s + e) / 2;					// [s:(s+e)/2] 구간 확인
		if (mid - s < 4) mid = s + 4;		// [s:(s+e)/2] 가 5개가 안된다면 [s:s+4]로 설정

		n = 0;
		for (int i = s; i <= mid; i++) 
            sub[n++] = v[i];

		if (query(n, sub, 0) == x)
            e = mid;	// 확인한 구간에 있는 경우
		else
            s = mid + 1;					// 확인한 구간에 없는 경우
	}

	n = 0;									// [s:e] 구간에 포함되지 않게 4개 설정
	for (int i = 0; n < 4; i++)
		if (i<s || i>e) 
            sub[n++] = v[i];

	for (int i = s; i <= e; i++) {			// [s:e] 구간 값은 한개씩 추가하여 rank가 x인 값 구하기
		sub[4] = v[i];

		if (query(5, sub, 0) == x) 
            return v[i];
	}

    return 0;
}

void getRank(int retRank[N])
{
	v.clear();
	for (int i = 0; i < N; i++) v.push_back(i);

	for (int i = 0; i < 4; i++) {	// rank 0~3 까지 값 구하기
		minv[i] = find(i);
		retRank[minv[i]] = i;
		v.erase(find(v.begin(), v.end(), minv[i]));
	}
	for (int i = 0; i < 4; i++) sub[i] = minv[i];	// rank 0~3 + 다른 값으로 쿼리 호출하여 rank 구하기
	for (int x : v) {
		sub[4] = x;
		retRank[x] = query(5, sub, 1);
	}
} 

//*** main.cpp ***/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include <stdio.h>
 
//const int N = 1000;
const int MAXQUERY = 1000000;
 
extern void getRank(int retRank[N]);
 
static int ansRank[N];
static int isused[N];
 
static bool okay;
static int  querycount;
 
int query(int M, int sub[], int opt)
{
    if (!okay || M < 5 || M > N || (opt != 0 && opt != 1) || querycount >= MAXQUERY)
    {
        okay = false;
        return -1;
    }
 
    ++querycount;
 
    if (opt == 0)
    {
        int ret = N - 1;
        for (int k = 0; k < M; ++k)
        {
            if (sub[k] < 0 || sub[k] >= N || isused[sub[k]] == querycount)
            {
                okay = false;
                return -1;
            }
 
            isused[sub[k]] = querycount;
 
            if (ret > ansRank[sub[k]])
                ret = ansRank[sub[k]];
        }
        return ret;
    }
    else
    {
        int ret = 0;
        for (int k = 0; k < M; ++k)
        {
            if (sub[k] < 0 || sub[k] >= N || isused[sub[k]] == querycount)
            {
                okay = false;
                return -1;
            }
 
            isused[sub[k]] = querycount;
 
            if (ret < ansRank[sub[k]])
                ret = ansRank[sub[k]];
        }
        return ret;
    }
}
 
static int callcount;
 
static bool run()
{
    int limit;
    int retRank[N];
 
    okay = true;
    for (int c = 0; c < 10; ++c)
    {
        limit = 1200;
 
        for (int i = 0; i < N; ++i)
            scanf("%d", &ansRank[i]);
 
        querycount = 0;
        for (int i = 0; i < N; ++i)
            isused[i] = 0;
 
        if (okay)
            getRank(retRank);
 
        if (limit < querycount)
            okay = false;
 
        if (okay)
        {
            for (int i = 0; i < N; i++)
                if (ansRank[i] != retRank[i])
                    okay = false;
        }
 
        callcount += querycount;
    }
 
    return okay;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
 
    int T, MARK;
    scanf("%d %d", &T, &MARK);
 
    int totalcount = 0;
    for (int tc = 1; tc <= T; tc++)
    {
        int score;
 
        callcount = 0;
        score = run() ? MARK : 0;
        printf("#%d %d %d\n", tc, score, callcount);
        totalcount += callcount;
    }
    printf("totalcount = %d, average = %.3lf\n", totalcount, (totalcount / (T * 10.)));
    return 0;
}

