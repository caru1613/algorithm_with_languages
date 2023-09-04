#include <cstdio>

int N;

struct Data
{
    int id;
    int s;
    int e;
} meet[510], tmp[510];

void msort(int s, int e)
{
    if (s>=e)
        return;

    int m = (s+e) >> 1;

    msort(s,m);
    msort(m+1,e);

    int i = s, j = m+1, k = s;

    while ( i <= m && j <= e)
    {
        if(meet[i].e < meet[j].e)
            tmp[k++] = meet[i++];
        else
            tmp[k++] = meet[j++];
    }

    while (i <= m)
        tmp[k++] = meet[i++];
    while (j <= e)
        tmp[k++] = meet[j++];

    for (i = s; i <=e; i++)
        meet[i] = tmp[i];

}

int main()
{
    int i, flag = 0, cnt = 0, ans[510];
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &meet[i].id, &meet[i].s, &meet[i].e); 
    }
    msort(0, N-1);

    for(i = 0; i < N; i++)
    {
        if (meet[i].s >= flag) {
            ans[cnt++] = meet[i].id;
            flag = meet[i].e;
        }
    }

    printf("%d\n", cnt);

    for (i = 0; i < cnt; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
