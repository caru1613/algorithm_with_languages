#include "SinglyLinkedList.h"
#include <iostream>

Node* SinglyLinkedList::CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SinglyLinkedList::DestroyNode(Node* Node)
{
    delete Node;
}

void SinglyLinkedList::AppendNode(Node* NewNode)
{
    cout << "Before assign NewNode to HEAD " << endl;
    cout << Head << endl;
    cout << NewNode << endl;

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
    }

    cout << "After assign NewNode to HEAD " << endl;
    cout << Head << endl;
    cout << NewNode << endl;

    return;
}

void SinglyLinkedList::InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
    return;
}

void SinglyLinkedList::InsertNewHead(Node* NewHead)
{
    if (Head == NULL)
    {
        Head = NewHead;
    }
    else
    {
        NewHead->NextNode = Head;
        Head = NewHead; 
    }
    return;
}

void SinglyLinkedList::RemoveNode(Node* Remove)
{
    if (Head == Remove)
    {
        Head = Remove->NextNode;
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
        }
    }
}

Node* SinglyLinkedList::GetNodeAt(int Location)
{
    Node* Current = Head;

    cout << __func__ << " Init " << Current <<  endl;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
        cout << __func__ << " Loop " << Current <<  endl;
    }

    cout << __func__ << " End " << Current <<  endl;
    return Current;
}

int SinglyLinkedList::GetNodeCount(void)
{
    return NodeCount;
}

void SinglyLinkedList::PrintNode(void)
{
    Node* node;

    for (node = Head; node != NULL; node = node->NextNode)
    {
        cout << node << " " << node->Data << endl;
    }
    cout << endl;
}

SinglyLinkedList::SinglyLinkedList(void)
{
    Head = NULL;
    NodeCount = 0;
}

