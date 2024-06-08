#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int dataSet[], int left, int right)
{
    int pivot_index = left;
    int pivot_value = dataSet[pivot_index];

    ++left;

    while (left <= right)
    {
        while (dataSet[left] <= pivot_value && left < right)
        {
            ++left;
        }

        while (dataSet[right] >= pivot_value && left <= right)
        {
            --right;
        }

        if (left < right)
        {
            swap(dataSet[left], dataSet[right]);
        }
        else
        {
            break;
        }
    }

    swap(dataSet[pivot_index], dataSet[right]);

    return right;
}

void quickSort(int dataSet[], int left, int right)
{
    if (left < right)
    {
        int index = partition(dataSet, left, right);
        
        quickSort(dataSet, left, index-1);
        quickSort(dataSet, index+1, right);
    }
}

int main()
{

    int dataSet[] = {6, 4, 2, 3, 1, 5};
    int length = sizeof(dataSet) / sizeof(dataSet[0]);
    int i = 0;

    cout << "Length: " << length << endl;;
    cout << "Unsorted data set" << endl;
    for ( i = 0; i < length; i++)
    {
        cout << dataSet[i] << " ";
    }
    cout << endl;

    quickSort(dataSet, 0, length-1);

    cout << "Sorted data set" << endl;
    for ( i = 0; i < length; i++)
    {
        cout << dataSet[i] << " ";
    }
    cout << endl;

    return 0;
}
