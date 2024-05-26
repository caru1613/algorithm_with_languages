#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &dataSet, int length)
{
    int i = 0, j = 0, temp = 0;

#if 0
    for ( i = 0; i < length; i++)
    {
        for ( j = 0; j < length-(i+1); j++)
        {
            if (dataSet[j] > dataSet[j+1])
            {
                temp = dataSet[j+1];
                dataSet[j+1] = dataSet[j];
                dataSet[j] = temp;
            }
        }
    }
#else
    for (vector<int>::iterator iter_1 = dataSet.begin(); iter_1 != dataSet.end(); ++iter_1)
    {
        for ( vector<int>::iterator iter_2 = dataSet.begin(); iter_2 != (dataSet.end() - (iter_1 - dataSet.begin()) - 1); ++iter_2)
        {
            if (*iter_2 > *(iter_2+1))
            {
                temp = *iter_2;
                *iter_2 = *(iter_2+1);
                *(iter_2+1) = temp;
            }
        }
    }
#endif
}

int main()
{
    vector<int> dataSet;
    dataSet.push_back(6);
    dataSet.push_back(4);
    dataSet.push_back(2);
    dataSet.push_back(3);
    dataSet.push_back(1);
    dataSet.push_back(5);
        
    int length = dataSet.size();
    cout << "origin dataSet: ";
    for (vector<int>::iterator iter = dataSet.begin(); iter != dataSet.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    cout << "Length: " << length << endl;

    int i = 0;

    BubbleSort(dataSet, length);

    cout << "Sorted dataSet: ";
    for (vector<int>::iterator iter = dataSet.begin(); iter != dataSet.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
