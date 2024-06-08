#include <iostream>

using namespace std;

int compare(const void* _elem1 , const void* _elem2)
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if (*elem1 > *elem2)
    {
        return 1;
    }
    else if (*elem1 < *elem2)
    {
        return -1;
    }
    else
    {
        return 0;
    }

    return 0;
}

int main()
{
    int scoreList[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int length = sizeof(scoreList) / sizeof(scoreList[0]);
    int target;
    int* ret;

    target = 11;
    ret = (int *)bsearch((void*)&target, (void*)scoreList, length, sizeof(scoreList[0]), compare);
    cout << ret << endl;
    if (ret)
    {
        cout << *ret << endl;
    }

    target = 20;
    ret = (int *)bsearch(&target, scoreList, length, sizeof(scoreList[0]), compare);
    cout << ret << endl;
    if (ret)
    {
        cout << *ret << endl;
    }

    return 0;
}
