#include <iostream>

using namespace std;

void insertionSort(int dataSet[], int length)
{
    int i, j, value;
    for (i = 1; i < length; i++)
    {
        if (dataSet[i-1] <= dataSet[i])
            continue;

        value = dataSet[i];

        for (j = 0; j < i ; j++)
        {
            if (dataSet[j] > value)
            {
                memmove(&dataSet[j+1], &dataSet[j], sizeof(dataSet[0]) * (i-j));
                dataSet[j] = value;
                break;
            }
        }
    }
}

int main()
{
    int data[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0};

    int i, j, value;

    insertionSort(data, 10);

    for (i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
