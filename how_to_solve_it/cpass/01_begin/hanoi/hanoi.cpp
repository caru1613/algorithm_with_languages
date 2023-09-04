#include <iostream>
#include <cstdio>

using namespace std;

void hanoi1(int n, int s, int e)
{
    if (n == 0)
        return;

    hanoi1(n-1, s, 6-s-e);
    cout << n << " : " << s  << " -> " << e << endl; // move from s to e
    hanoi1(n-1, 6-s-e, e);

}

void hanoi2(int n, int s, int e, int b)
{
    if (n == 0)
        return;

    hanoi2(n-1, s, b, e);
    cout << n << " : " << s  << " -> " << e << endl; // move from s to e
    hanoi2(n-1, b, e, s);

}

int main()
{
    int N;
    scanf("%d", &N);
    cout << "=== hanoi1 === " << endl;
    hanoi1(N, 1, 3);

    cout << "=== hanoi2 === " << endl;
    hanoi2(N, 1, 3, 2);

    return 0;
}
