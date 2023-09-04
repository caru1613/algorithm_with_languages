#include <cstdio>

///===== user.cpp =====

#define SIZE 100000

int idxArr[SIZE];
int trr[SIZE];

// return 1 if left value is smaller than right.
// return 0 else.
extern int orderCheck(int left, int right);

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int m = (s + e) / 2;

    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);

    int i = s, j = m+1, k = s;

    while (i <= m && j <= e)
    {
        // return 1 if left value is smaller than right.
        // return 0 else.
        if (orderCheck(arr[i], arr[j]))
            trr[k++] = arr[i++];
        else
            trr[k++] = arr[j++];
    }

    while (i <= m)
        trr[k++] = arr[i++];
    while (j <= e)
        trr[k++] = arr[j++];

    for (int i = s; i <= e; i++)
        arr[i] = trr[i];
}


void array_restore(int arrCount, int dat[]){
    // implement here

    for (int i = 0; i < arrCount; i++)
        idxArr[i] = i;

    mergeSort(idxArr, 0, arrCount-1);

    for(int i = 0; i < arrCount; i++)
        dat[idxArr[i]] = i+1;
 
}
 
///====== main.cpp =====
 
 
#include <stdio.h>
#define MAXSIZE 100000
 
static int org[MAXSIZE], dat[MAXSIZE];
static int arrCount, QueryCount;
 
extern void array_restore(int arrCount, int dat[]);
 
// ISO9899
static unsigned long int next = 1;
int rand(void) // RAND_MAX assumed to be 65535
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next >> 16) & 65535;
}
 
int orderCheck(int left, int right)
{
    QueryCount++;
    if (left<0 || left>=arrCount) return 1;
    if (right<0 || right>=arrCount) return 1;
    if (org[left] < org[right]) return 1;
    else return 0;
}
 
inline void Swap(int&a, int&b){
    int t = a; a = b; b = t;
}
 
static void init(int t)
{
    int i, j;
    QueryCount = 0;
    arrCount = (t * 2000 - 1000) + rand() % 1000;
    for (i = 0; i < arrCount; i++) {
        org[i] = i + 1;
        dat[i] = 0;
    }
    for (i = 0; i < arrCount; i++){
        j = (int)((long long)rand() * rand() % arrCount);
        Swap(org[i], org[j]);
    }
}
 
static int arr_comp()
{
    if (QueryCount >= arrCount * 20) return MAXSIZE * 100;
    for (int i = 0; i < arrCount; i++) {
        if (org[i] != dat[i]) return MAXSIZE * 100;
    }
    return QueryCount;
}
 
int main(void)
{
    for (int tc = 1; tc <= 50; tc++)
    {
        init(tc);
        array_restore(arrCount, dat);
        printf("#%d %d %d\n", tc, arrCount, arr_comp());
    }
 
    return 0;
}
