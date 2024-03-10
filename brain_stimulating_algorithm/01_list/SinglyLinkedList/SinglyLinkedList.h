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
    private:
        Node *Head;
        Node *Current;
        unsigned int NodeCount;
        
    public:
        Node* CreateNode(ElementType NewData);
        void DestroyNode(Node* Node);
        void AppendNode(Node* NewNode);
        void InsertAfter(Node* Current, Node* NewNode);
        void InsertNewHead(Node* NewHead);
        void RemoveNode(Node* RemoveNode);
        Node* GetNodeAt(int Location);
        int GetNodeCount(void);
        void PrintNode(void);

        SinglyLinkedList();
};

#endif
