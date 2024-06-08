#include <iostream>

using namespace std;

int binarySearch(int scoreList[], int size, int target)
{
    int left, right, mid;

    left = 0;
    right = size - 1;

    while(left <= right)
    {
        mid = (left + right) / 2;

        if(target == scoreList[mid])
        {
            return mid;
        }
        else if (target > scoreList[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int scoreList[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int length = sizeof(scoreList) / sizeof(scoreList[0]);
    int ret;

    ret = binarySearch(scoreList, length, 5);
    cout << ret << endl;

    ret = binarySearch(scoreList, length, 8);
    cout << ret << endl;

    return 0;
}
