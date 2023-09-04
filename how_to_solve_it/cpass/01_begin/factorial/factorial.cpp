#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long factorial(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        printf("%d! = %d\n", n, n);
    else
        printf("%d! = %d * %d!\n", n, n, n-1);

    return n * factorial(n-1);
}

int main()
{
    int N;
    scanf("%d", &N);

    printf("%lld\n", factorial(N));

    return 0;
}
