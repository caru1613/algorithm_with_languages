#include <cstdio>
#include <iostream>

#define SIZE 500500

int N_data[SIZE];
int Q_data;
int N, Q;

int binary_search_loop(int *data, int s, int e, int target)
{
    int m;

    while (s <= e)
    {
        m = (s+e)/2;

        if (data[m] == target)
            return m;
        else if (data[m] > target)
            e = m-1;
        else if (data[m] < target)
            s = m+1;
        else
            return -1;
    }

    return -1;
}

int binary_search_recursive(int *data, int s, int e, int target)
{
    if( s > e )
        return -1;

    int m = (s+e)/2;

    if (data[m] == target)
        return m;
    else if(data[m] > target)
        return binary_search_recursive(data, s, m-1, target);
    else if(data[m] < target)
        return binary_search_recursive(data, m+1, e, target);

    /* Never happened */
    return -1;
}

int main()
{
    int ret;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &N_data[i]);
    }

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        scanf(" %d", &Q_data);
        ret = binary_search_loop(N_data, 0, N, Q_data);
        printf("%d ", ret);
    }
    printf("\n");

    return 0;
}
