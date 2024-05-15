
#include "DisjointSet.h"
#include <iostream>

using namespace std;

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    DisjointSet disjointSet;
    DisjointSetNode* set1 = disjointSet.makeSet(&a);
    DisjointSetNode* set2 = disjointSet.makeSet(&b);
    DisjointSetNode* set3 = disjointSet.makeSet(&c);
    DisjointSetNode* set4 = disjointSet.makeSet(&d);
    bool compareResult;

    compareResult = disjointSet.findSet(set1) ==  disjointSet.findSet(set2);
    cout << "set1 == set2 : " << compareResult << endl;

    disjointSet.unionSet(set1, set3);
    compareResult = disjointSet.findSet(set1) ==  disjointSet.findSet(set3);
    cout << "set1 == set3 : " << compareResult << endl;

    disjointSet.unionSet(set3, set4);
    compareResult = disjointSet.findSet(set3) ==  disjointSet.findSet(set4);
    cout << "set3 == set4 : " << compareResult << endl;

    //disjointSet.destroySet(&a);
    //disjointSet.destroySet(&b);
    //disjointSet.destroySet(&c);
    //disjointSet.destroySet(&d);

    return 0;
}
