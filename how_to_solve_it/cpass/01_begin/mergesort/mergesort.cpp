#include <cstdio>
#include <iostream>

using namespace std;

#define SIZE 1010
int arr[SIZE] = {0};
int tmp[SIZE] = {0};

int N;

void print()
{
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int s, int e)
{
    if (s >= e)
        return;

//    cout << s << "," << e << endl;

    int m = (s + e) / 2;
    
    mergeSort(s, m);
    mergeSort(m+1, e);

    int t = s;
    int l = s;
    int u = m+1;

//    cout << t << "," << l << "," << u << endl;

    while (l <= m && u <= e)
    {
        if( arr[l] <= arr[u])
        {
            tmp[t++] = arr[l++];
        }
        else
        {
            tmp[t++] = arr[u++];
        }
    }

    while (l <= m)
    {
        tmp[t++] = arr[l++];
    }

    while (u <= e)
    {
        tmp[t++] = arr[u++];
    }

    t = s;
    while (t <= e)
    {
        arr[t] = tmp[t];
        t++;
    }

    print();
}


int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    //print();
    mergeSort(0, N-1);
    //print();

    return 0;
}
