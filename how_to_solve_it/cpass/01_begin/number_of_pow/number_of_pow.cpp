#include <iostream>
#include <cstdio>

int n_of_pow(unsigned long long x, unsigned long long y)
{
    if (y <= 0)
        return 1;

    if (y % 2)
        return (n_of_pow(x, y-1) * x) % 20091024;

    unsigned long long tmp = n_of_pow(x, y/2);

    return tmp * tmp % 20091024;
}

int main()
{
    unsigned long long X, Y, ret;

    scanf("%lld %lld", &X, &Y);
    
    ret = n_of_pow(X, Y);
    printf("%lld\n", ret);

    return 0;
}

