#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

void test_SingleNode(void)
{
    cout << __func__ << endl;

    Node *NewNode;
    Node *TempNode;

    SinglyLinkedList singlylinkedlist;

    NewNode = singlylinkedlist.CreateNode(10);
    singlylinkedlist.AppendNode(NewNode);
    singlylinkedlist.PrintNode();

    TempNode = singlylinkedlist.GetNodeAt(0);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        NewNode = TempNode;
    }

    singlylinkedlist.RemoveNode(NewNode);
    singlylinkedlist.DestroyNode(NewNode);
    singlylinkedlist.PrintNode();

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

    SinglyLinkedList singlylinkedlist;

    NewNode1 = singlylinkedlist.CreateNode(10);
    singlylinkedlist.AppendNode(NewNode1);
    singlylinkedlist.PrintNode();

    NewNode2 = singlylinkedlist.CreateNode(20);
    singlylinkedlist.AppendNode(NewNode2);
    singlylinkedlist.PrintNode();

    TempNode = singlylinkedlist.GetNodeAt(0);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        RemoveNode1 = TempNode;
    }

    TempNode = singlylinkedlist.GetNodeAt(1);
    if (TempNode == NULL)
        cout << "NewNode is NULL " << endl;
    else 
    {
        RemoveNode2 = TempNode;
    }

    singlylinkedlist.RemoveNode(RemoveNode1);
    singlylinkedlist.DestroyNode(RemoveNode1);
    singlylinkedlist.PrintNode();

    singlylinkedlist.RemoveNode(RemoveNode2);
    singlylinkedlist.DestroyNode(RemoveNode2);
    singlylinkedlist.PrintNode();

    return;
}

int main(void)
{
    cout << "SinglyLinkedList test" << endl;
    test_SingleNode();
    test_MultiNode();

    return 0;
}
