#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

void test_SingleNode(void)
{
    cout << __func__ << endl;

    Node *NewNode;
    Node *TempNode;

    CircularLinkedList doublelinkedlist;

    NewNode = doublelinkedlist.CreateNode(10);
    doublelinkedlist.AppendNode(NewNode);
    doublelinkedlist.PrintNode();

    TempNode = doublelinkedlist.GetNodeAt(0);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        NewNode = TempNode;
    }

    doublelinkedlist.RemoveNode(NewNode);
    doublelinkedlist.DestroyNode(NewNode);
    doublelinkedlist.PrintNode();

    return;
}

void test_MultiNode(void)
{
    cout << __func__ << endl;

    Node *NewNode1;
    Node *NewNode2;
    Node *RemoveNode1;
    Node *RemoveNode2;
    Node *TempNode;

    CircularLinkedList doublelinkedlist;

    NewNode1 = doublelinkedlist.CreateNode(10);
    doublelinkedlist.AppendNode(NewNode1);
    doublelinkedlist.PrintNode();

    NewNode2 = doublelinkedlist.CreateNode(20);
    doublelinkedlist.AppendNode(NewNode2);
    doublelinkedlist.PrintNode();

    TempNode = doublelinkedlist.GetNodeAt(0);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        RemoveNode1 = TempNode;
    }

    TempNode = doublelinkedlist.GetNodeAt(1);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        RemoveNode2 = TempNode;
    }

    doublelinkedlist.RemoveNode(RemoveNode1);
    doublelinkedlist.DestroyNode(RemoveNode1);
    doublelinkedlist.PrintNode();

    doublelinkedlist.RemoveNode(RemoveNode2);
    doublelinkedlist.DestroyNode(RemoveNode2);
    doublelinkedlist.PrintNode();

    return;
}

int main(void)
{
    cout << "CircularLinkedList test" << endl;
    test_SingleNode();
    test_MultiNode();

    return 0;
}
