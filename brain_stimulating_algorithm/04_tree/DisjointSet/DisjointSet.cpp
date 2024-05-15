
#include "DisjointSet.h"
#include <iostream>

using namespace std;

void DisjointSet::unionSet(DisjointSetNode* set1, DisjointSetNode* set2)
{
    cout << __func__ << endl;

    set2 = findSet(set2);  

    set2->parent = set1;
}

DisjointSetNode* DisjointSet::findSet(DisjointSetNode* set)
{
    cout << __func__ << endl;

    while (set->parent != NULL)
    {
        set = set->parent; 
    }

    return set;
}

DisjointSetNode* DisjointSet::makeSet(void* data)
{
   cout << __func__ << endl;

   DisjointSetNode* node = new DisjointSetNode; 
   node->data = data;
   node->parent = NULL;

   return node;
}

void DisjointSet::destroySet(DisjointSetNode* set)
{
    cout << __func__ << endl;

    delete set;
}

