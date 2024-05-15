#ifndef __DISJOINTSET_H__
#define __DISJOINTSET_H__

typedef struct tagDisjointSetNode
{
    struct tagDisjointSetNode* parent;
    void* data;
} DisjointSetNode;

class DisjointSet
{
    public:
        void unionSet(DisjointSetNode* set1, DisjointSetNode* set2);
        DisjointSetNode* findSet(DisjointSetNode* set);
        DisjointSetNode* makeSet(void* data);
        void destroySet(DisjointSetNode* set);
};

#endif
