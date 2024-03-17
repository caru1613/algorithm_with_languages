#include "CircularLinkedList.h"
#include <iostream>

Node* CircularLinkedList::CreateNode(ElementType NewData)
{
    Node* NewNode = new Node;
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    cout << __func__ << " " << NewNode << " " << NewNode->Data << endl;
    return NewNode;
}

void CircularLinkedList::DestroyNode(Node* Node)
{
    cout << __func__ << " " << Node << endl;

    if (Node != NULL)
    {
        delete Node;
    }
}

void CircularLinkedList::AppendNode(Node* NewNode)
{
    cout << __func__ << " " << NewNode << " " << NewNode->Data << endl;

    if ( Head == NULL)
    {
        Head = NewNode;
        Head->PrevNode = Head;
        Head->NextNode = Head;
    }
    else
    {
        NewNode->PrevNode = Head->PrevNode;
        NewNode->NextNode = Head;

        Head->PrevNode->NextNode = NewNode;
        Head->PrevNode = NewNode;
    }

    return;
}

void CircularLinkedList::InsertAfter(Node* Current, Node* NewNode)
{
    cout << __func__ << " " << Current << " " << NewNode << " " << NewNode->Data << endl;

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode = NewNode;
    return;
}

void CircularLinkedList::InsertNewHead(Node* NewHead)
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

void CircularLinkedList::RemoveNode(Node* Remove)
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

Node* CircularLinkedList::GetNodeAt(int location)
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

int CircularLinkedList::GetNodeCount(void)
{
    cout << __func__ << " " << NodeCount << endl;
    return NodeCount;
}

void CircularLinkedList::PrintNode(void)
{
    Node* node;

    cout << "Print Nodes in List" << endl;
    for (node = Head; node != NULL; node = node->NextNode)
    {
        cout << node << " " << node->Data << endl;
    }
    cout << endl;
}

CircularLinkedList::CircularLinkedList(void)
{
    cout << __func__ << " " << Head << endl;
    Head = NULL;
    NodeCount = 0;
}

