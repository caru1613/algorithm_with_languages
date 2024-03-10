#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

int main(void)
{
    cout << "Hello world2" << endl;
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
        cout << TempNode->Data << endl;
        NewNode = TempNode;
        cout << NewNode->Data << endl;
    }

    singlylinkedlist.RemoveNode(NewNode);
    singlylinkedlist.DestroyNode(NewNode);
    singlylinkedlist.PrintNode();

    return 0;
}
