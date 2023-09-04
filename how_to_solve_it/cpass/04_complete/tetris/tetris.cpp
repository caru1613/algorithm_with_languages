/// *** main.cpp ***
#ifndef _CRT_SECURE_NO_wARNINGS
#define _CRT_SECURE_NO_wARNINGS
#endif

#include <cstring>
#include <queue>
using namespace std;

using pii = pair<int, int>;
const int LM = 201;
int h, w;
int board[LM][LM];
int mark[LM][LM];
int score[3];
int remain[3];
int height[LM];

int dr[4] = { -1, -1, 0, 1 };
int dc[4] = {  0,  1, 1, 1 };
int drc[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

queue<pii> que;

#undef DEBUG

#ifdef DEBUG
#define debug_print(...) printf(__VA_ARGS__)
#else
#define debug_print(...)
#endif

void push(int nr, int nc, int player)
{
    if (nr < 0 || nr >= h || nc < 0 || nc >= w || (board[nr][nc] != (player ^ 3)))
        return;

    que.push({nr, nc});
    --remain[board[nr][nc]];
    ++remain[board[nr][nc] = player];
}

void changeBFS( int r, int c, int player)
{
    que = {};
    push(r, c, player);

    while(!que.empty())
    {
        pii t = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            push(t.first + drc[i][0], t.second + drc[i][1], player);
        }
    }
}

int eraseBlock(int player)
{
    int cnt = 0;

    for(int c = 0; c < w; ++c)
    {
        int r1 = h - 1;
        int r2 = h - 1;

        while (r1 >= height[c])
        {
            if (mark[r1][c])
            {
                if(board[r1][c] == player)
                    ++cnt;
                mark[r1][c] = 0;
                --remain[board[r1][c]];
                --r1;
            }
            else
            {
                board[r2--][c] = board[r1--][c];
            }
        }

        height[c] = r2 + 1;
        while ( r2 > r1 )
        {
            board[r2--][c] = 0;
        }
    }

    return cnt;
}

int search(int r, int c, int rr, int cc, int color)
{
    int cnt = 0;
    while (r >= 0 && r < h && c >= 0 && c < w && board[r][c] == color)
    {
        cnt++;
        r += rr;
        c += cc;
    }

    return cnt;
}

void eraseMark(int r, int c, int rr, int cc, int len)
{
    for (int i = 0; i < len; ++i, r += rr, c += cc)
    {
        mark[r][c] = 1;
    }
}

int updateAll(int player)
{
    int ret = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int c = 0; c < w; ++c)
        {
            for (int r = h -1; r >= height[c]; --r)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int len = search(r, c, dr[k], dc[k], board[r][c]);
                    if (len >= 5)
                    {
                        eraseMark(r, c, dr[k], dc[k], len);
                        flag = true;
                    }
                }
            }
        }
        if (!flag)
            break;
        ret += eraseBlock(player);
    }

    score[player] += ret;
    return ret;
}

int updateTop(int player, int col)
{
    int ret = 0;
    bool flag = false;

    for (int c = col; c < col + 3; ++c)
    {
        int r = height[c];
        for (int k = 0; k < 4; ++k)
        {
            int len1 = search(r, c, dr[k], dc[k], player);
            int len2 = search(r, c, -dr[k], -dc[k], player);

            if (len1 + len2 > 5)
            {
                eraseMark(r, c, dr[k], dc[k], len1);
                eraseMark(r, c, -dr[k], -dc[k], len2);

                flag = true;
            }
        }
    }

    if (!flag)
        return 0;

    ret = eraseBlock(player);
    score[player] += ret;

    return ret;
}

/// *** user.cpp ***
void init(int W, int H) {
 
    h = H;
    w = W;
    memset(board, 0, sizeof(board));
    memset(mark, 0, sizeof(mark));

    for (int c = 0; c < w; ++c)
        height[c] = h;
    score[1] = 0;
    score[2] = 0;
    remain[1] = 0;
    remain[2] = 0;
}

int dropBlocks(int player, int col) {
    for (int c = col; c < col + 3; ++c)
    {
        board[--height[c]][c] = player;
        ++remain[player];
    }

    int ret = updateTop(player, col);
    if (ret == 0)
        return 0;
    ret += updateAll(player);

    debug_print("%s: ret: %d.\n", __func__, ret);
    return ret;
}

int changeBlocks(int player, int col) {

    if (board[h -1][col] == 0 || board[h - 1][col] == player)
        return 0;
    changeBFS(h - 1, col, player);
    int ret = updateAll(player);

    debug_print("%s: ret: %d.\n", __func__, ret);
    return ret;
}

int getResult(int blockCnt[2]) {

    blockCnt[0] = remain[1];
    blockCnt[1] = remain[2];

    int ret = score[1] == score[2] ? 0 : (score[1] > score[2] ? 1: 2);

    debug_print("%s: ret: %d.\n", __func__, ret);
    return ret;
}
 
#include <stdio.h>
 
#define INIT   (100)
#define DROP   (200)
#define CHANGE (300)
#define GETRET (400)
 
extern void init(int W, int H);
extern int dropBlocks(int player, int col);
extern int changeBlocks(int player, int col);
extern int getResult(int blockCnt[2]);
 
static bool run()
{
    int Q, W, H;
 
    int player, col;
 
    int ret = -1, ans;
    int blockCnt[2] = {};
    int r1, r2;
 
    scanf("%d", &Q);
 
    bool okay = false;
    for (int q = 0; q < Q; ++q)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case INIT:
            scanf("%d %d", &W, &H);
            init(W, H);
            okay = true;
            break;
        case DROP:
            scanf("%d %d", &player, &col);
            if (okay)
                ret = dropBlocks(player, col);
            scanf("%d", &ans);
            if (ret != ans)
                okay = false;
            break;
        case CHANGE:
            scanf("%d %d", &player, &col);
            if (okay)
                ret = changeBlocks(player, col);
            scanf("%d", &ans);
            if (ret != ans)
                okay = false;
            break;
        case GETRET:
            if (okay)
                ret = getResult(blockCnt);
            scanf("%d %d %d", &ans, &r1, &r2);
            if (ans != ret || blockCnt[0] != r1 || blockCnt[1] != r2)
                okay = false;
            break;
        default:
            okay = false;
            break;
        }
    }
 
    return okay;
}
 
int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
 
    int T, SUCCESS;
    scanf("%d%d", &T, &SUCCESS);
    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? SUCCESS : 0;
        printf("#%d %d\n", tc, score);
    }
 
    return 0;
}
