#include <iostream>

using namespace std;

int compare(const void *_elem1, const void *_elem2)
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
    int dataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(dataSet) / sizeof(dataSet[0]);
    int i = 0;

    cout << "Before sort" << endl;
    for (i = 0; i < length; i++)
    {
       cout << dataSet[i] << " ";
    }
    cout << endl;

    cout << "After sort" << endl;
    qsort( (void*)dataSet, length, sizeof(int), compare );

    for (i = 0; i < length; i++)
    {
       cout << dataSet[i] << " ";
    }
    
    cout << endl;

    return 0;
}
