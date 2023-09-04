/* union find 코드 활용
 * (N/10)*(N/10) 크기 단위로 분류하여 총 10*10 개의 버킷에 딱지들을 등록한다.
 * 딱지가 포함되는 모든 버킷에 등록. 최대 2*2=4개에 등록
*/
#include<vector>
using namespace std;

const int LM = 20003;
int root[LM], rnk[LM];  // 딱지 상위노드 , 그룹의 높이
int cnt[LM], pid[LM];   // 그룹의 딱지 개수 , 그룹의 소유 플레이어 번호(1,2)
int sx[LM], sy[LM], ex[LM], ey[LM];
int pcnt[3];            // 플레이어의 딱지 개수
int n, m;               // 총 딱지 개수, N(격자 크기)/10
vector<int> v[10][10];  // 딱지 분류

int find(int x) {                   // 최상위 노드를 찾는 과정, 검색한 노드들의 root를 찾은 최상위 노드로 업데이트
    if (root[x] == x) return x;
    return root[x] = find(root[x]); // 경로압축
}

/* 그룹의 최상위 노드에 옳바른 pid,cnt,rank가 저장되어야함, 하위노드들은 필요없음
 * y는 항상 마지막 딱지이므로 x그룹의 소유가 마지막 딱지를 놓은 플레이어가 된다. */
void union_(int x, int y) {
    x = find(x), y = find(y);   // x, y의 최상위 노드 설정
    if (x == y) return;         // 이미 같은 그룹인 경우

    /* y 딱지 소유 플레이어의 딱지 개수 업데이트*/
    pcnt[pid[x]] -= cnt[x], pcnt[pid[y]] += cnt[x];

    /* rank가 작은 그룹을 큰 그룹으로 연결 */
    if (rnk[x] < rnk[y]) {   // x를 y로 연결
        root[x] = y;
        cnt[y] += cnt[x];   // 새로운 그룹의 최상위 노드는 y이므로
    }
    else {
        root[y] = x;        // y를 x로 연결
        cnt[x] += cnt[y];   // 새로운 그룹의 최상위 노드는 x이므로
        pid[x] = pid[y];

        if (rnk[x] == rnk[y]) rnk[x]++;     // 높이가 같은 두 그룹을 연결하면 높이가 1 증가한다.
    }
}

void init(int N, int M)
{
    n = pcnt[1] = pcnt[2] = 0;
    m = M;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) v[i][j].clear();
}

int add(int mRow, int mCol, int mSize, int mPlayer)
{
    // 딱지 정보 초기화
    root[n] = n;        // 본인을 최상위 노드로 해서 한개짜리 그룹 생성
    rnk[n] = 0;
    pid[n] = mPlayer;
    cnt[n] = 1;

    pcnt[mPlayer]++;    // mPlayer의 딱지 한개 추가
    sx[n] = mRow, sy[n] = mCol;
    ex[n] = mRow + mSize - 1, ey[n] = mCol + mSize - 1;

    /* 새로운 딱지가 포함된 버킷에 존재하는 딱지들만 검색 */
    for (int i = sx[n] / m; i <= ex[n] / m; i++) {       // 1~2개
        for (int j = sy[n] / m; j <= ey[n] / m; j++) {   // 1~2개
            for (int c : v[i][j]) {
                if (ex[c] < sx[n] || ex[n] < sx[c] || ey[n] < sy[c] || ey[c] < sy[n]) continue;
                union_(c, n);
            }
            v[i][j].push_back(n);
        }
    }

    n++;
    return pcnt[mPlayer];
}

int get(int mRow, int mCol)
{
    for (int c : v[mRow / m][mCol / m]) // (mRow, mCol)의 버킷에 포함된 딱지들만 확인
        if (sx[c] <= mRow && mRow <= ex[c] && sy[c] <= mCol && mCol <= ey[c]) return pid[find(c)];
    return 0;
}

/********** main.cpp ***********/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
 
#include<stdio.h>
 
extern void init(int, int);
extern int add(int, int, int, int);
extern int get(int, int);
 
static unsigned int seed = 5;
static int pseudo_rand(void)
{
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}
 
static int board_size, ddakji_size, query_cnt;
 
static int run(int score)
{
    scanf("%d%d%d%d", &seed, &board_size, &ddakji_size, &query_cnt);
    init(board_size, ddakji_size);
 
    for (int q = 0; q < query_cnt; q++)
    {
        int r, c, size, user_ans, correct_ans;
 
        size = (pseudo_rand() * pseudo_rand()) % ddakji_size + 1;
        r = (pseudo_rand() * pseudo_rand()) % (board_size - size + 1);
        c = (pseudo_rand() * pseudo_rand()) % (board_size - size + 1);
 
        user_ans = add(r, c, size, 1);
        scanf("%d", &correct_ans);
 
        if (user_ans != correct_ans) {
            score = 0;
        }
 
        size = (pseudo_rand() * pseudo_rand()) % ddakji_size + 1;
        r = (pseudo_rand() * pseudo_rand()) % (board_size - size + 1);
        c = (pseudo_rand() * pseudo_rand()) % (board_size - size + 1);
 
        user_ans = add(r, c, size, 2);
        scanf("%d", &correct_ans);
 
        if (user_ans != correct_ans) {
            score = 0;
        }
 
        r = (pseudo_rand() * pseudo_rand()) % (board_size);
        c = (pseudo_rand() * pseudo_rand()) % (board_size);
 
        user_ans = get(r, c);
        scanf("%d", &correct_ans);
 
        if (user_ans != correct_ans) {
            score = 0;
        }
    }
 
    return score;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
 
    int tc, score;
    scanf("%d%d", &tc, &score);
 
    for (int t = 1; t <= tc; t++)
    {
        int t_score = run(score);
 
        printf("#%d %d\n", t, t_score);
    }
 
    return 0;
}
 

