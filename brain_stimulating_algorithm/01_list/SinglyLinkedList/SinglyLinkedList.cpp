#include "SinglyLinkedList.h"
#include <iostream>

Node* SinglyLinkedList::CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    cout << __func__ << " " << NewNode << " " << NewNode->Data << endl;
    return NewNode;
}

void SinglyLinkedList::DestroyNode(Node* Node)
{
    cout << __func__ << " " << Node << endl;

    if (Node != NULL)
    {
        delete Node;
    }
}

void SinglyLinkedList::AppendNode(Node* NewNode)
{
    cout << __func__ << " " <<NewNode << " " << NewNode->Data << endl;

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

    return;
}

void SinglyLinkedList::InsertAfter(Node* Current, Node* NewNode)
{
    cout << __func__ << " " << Current << " " << NewNode << " " << NewNode->Data << endl;

    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
    return;
}

void SinglyLinkedList::InsertNewHead(Node* NewHead)
{
    cout << __func__ << " " << Head << " " << NewHead << endl;

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
    cout << __func__ << " " <<Remove << endl;
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

Node* SinglyLinkedList::GetNodeAt(int location)
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

int SinglyLinkedList::GetNodeCount(void)
{
    cout << __func__ << " " << NodeCount << endl;
    return NodeCount;
}

void SinglyLinkedList::PrintNode(void)
{
    Node* node;

    cout << "Print Nodes in List" << endl;
    for (node = Head; node != NULL; node = node->NextNode)
    {
        cout << node << " " << node->Data << endl;
    }
    cout << endl;
}

SinglyLinkedList::SinglyLinkedList(void)
{
    cout << __func__ << " " << Head << endl;
    Head = NULL;
    NodeCount = 0;
}

