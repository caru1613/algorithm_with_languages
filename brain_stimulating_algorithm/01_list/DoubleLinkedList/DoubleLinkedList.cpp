#include "DoubleLinkedList.h"
#include <iostream>

Node* DoubleLinkedList::CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    cout << __func__ << " " << NewNode << " " << NewNode->Data << endl;
    return NewNode;
}

void DoubleLinkedList::DestroyNode(Node* Node)
{
    cout << __func__ << " " << Node << endl;

    if (Node != NULL)
    {
        delete Node;
    }
}

void DoubleLinkedList::AppendNode(Node* NewNode)
{
    cout << __func__ << " " << NewNode << " " << NewNode->Data << endl;

    if ( Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        Node* Tail = Head;

        while ( Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }

    return;
}

void DoubleLinkedList::InsertAfter(Node* Current, Node* NewNode)
{
    cout << __func__ << " " << Current << " " << NewNode << " " << NewNode->Data << endl;

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode = NewNode;
    return;
}

void DoubleLinkedList::InsertNewHead(Node* NewHead)
{
    cout << __func__ << " " << Head << " " << NewHead << endl;

    if (Head == NULL)
    {
        Head = NewHead;
    }
    else
    {
        NewHead->NextNode = Head;
        NewHead->PrevNode = NULL;
        Head->PrevNode = NewHead;
        Head = NewHead; 
    }
    return;
}

void DoubleLinkedList::RemoveNode(Node* Remove)
{
    cout << __func__ << " " << Remove << endl;
    if (Head == Remove)
    {
        Head = Remove->NextNode;
        if (Head != NULL)
        {
            Head->PrevNode = NULL;
        }
    }
    else
    {
        Node* Current = Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
            Remove->NextNode->PrevNode = Current;
        }
    }
}

Node* DoubleLinkedList::GetNodeAt(int location)
{
    Node* Current = Head;

    int loop = location;
    while (Current != NULL && (--loop) >= 0)
    {
        Current = Current->NextNode;
    }

    cout << __func__ << " " << location << " " << Current <<  endl;
    return Current;
}

int DoubleLinkedList::GetNodeCount(void)
{
    cout << __func__ << " " << NodeCount << endl;
    return NodeCount;
}

void DoubleLinkedList::PrintNode(void)
{
    Node* node;

    cout << "Print Nodes in List" << endl;
    for (node = Head; node != NULL; node = node->NextNode)
    {
        cout << node << " " << node->Data << endl;
    }
    cout << endl;
}

DoubleLinkedList::DoubleLinkedList(void)
{
    cout << __func__ << " " << Head << endl;
    Head = NULL;
    NodeCount = 0;
}

