#ifndef __SINGLYLINKEDLIST_H__
#define __SINGLYLINKEDLIST_H__

#include <iostream>
using namespace std;

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
} Node;

class SinglyLinkedList
{
    public:

    private:
        Node* CreateNode();
        void DestroyNode();
        void AppendNode();
        void InsertAfter();
        void InsertNewHead();
        void RemoveNode();
        Node* GetNodeAt();
        int GetNodeCount();
};

#endif