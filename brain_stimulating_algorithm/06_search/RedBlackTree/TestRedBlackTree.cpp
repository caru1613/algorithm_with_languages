#include "RedBlackTree.h"
#include <iostream>

using namespace std;

int main(void)
{
    RBTNode* tree = NULL;
    RBTNode* node = NULL;

    RedBlackTree RBT = RedBlackTree();
    while (1)
    {
        int cmd = 0;
        int param = 0;
        int buffer;

        cout << "Enter command number :" << endl;
        cout << "(1) Create a node" << endl;
        cout << "(2) Remove a node" << endl;
        cout << "(3) Search a node" << endl;
        cout << "(4) Display Tree" << endl;
        cout << "(5) Quit" << endl;
        cout << "command number:";

        cin >> cmd;

        if (cmd < 1 || cmd > 5)
        {
            cout << "Invalid command number." << endl;
            continue;
        }
        else if (cmd == 4)
        {
            RBT.printTree( tree, 0, 0 );
            cout << endl;
            continue;
        }
        else if (cmd == 5)
        {
            break;
        }

        cout << "Enter parameter (1-200) :" << endl;

        cin >> param;

        if ( param < 1 || param > 200)
        {
            cout << "Invalid parameter." << param << endl;
            continue;
        }

        switch(cmd)
        {
            case 1:
                RBT.insertNode(&tree, RBT.createNode(param));
                break;
            case 2:
                node = RBT.removeNode(&tree, param);

                if (node == NULL)
                {
                    cout << "Not found nod to delete: " << param << endl;
                }
                else
                {
                    RBT.destroyNode(node);
                }
                break;
            case 3:
                node = RBT.searchNode(tree, param);

                if (node == NULL)
                {
                    cout << "Not found node: " << param << endl;
                }
                else
                {
                    string color = (node->color == RED)?"RED":"BLACK";
                    cout << "Found node: " << node->data << "(Color:" << color << ")" << endl;
                }
                break;
            case 4:
            case 5:
            default:
                cout << "Invalid command number." << endl;
                continue;
        }

        cout << endl;
    }

    RBT.destroyTree(tree);
    return 0;
}
