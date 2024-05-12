
#include "SimpleBinaryTree.h"
#include <iostream>

using namespace std;

int main(void)
{
    SimpleBinaryTree simpleBinaryTree;

    SBTNode* a = simpleBinaryTree.createNode('A');
    SBTNode* b = simpleBinaryTree.createNode('B');
    SBTNode* c = simpleBinaryTree.createNode('C');
    SBTNode* d = simpleBinaryTree.createNode('D');
    SBTNode* e = simpleBinaryTree.createNode('E');
    SBTNode* f = simpleBinaryTree.createNode('F');
    SBTNode* g = simpleBinaryTree.createNode('G');

    a->left = b;

    b->left = c;
    b->right = d;

    a->right = e;
    e->left = f;
    e->right = g;

    cout << "Pre Order Tree" << endl;
    simpleBinaryTree.preorderPrintTree(a);
    cout << endl;
    cout << endl;

    cout << "In Order Tree" << endl;
    simpleBinaryTree.inorderPrintTree(a);
    cout << endl;
    cout << endl;

    cout << "Post Order Tree" << endl;
    simpleBinaryTree.postorderPrintTree(a);
    cout << endl;
    cout << endl;

    simpleBinaryTree.destroyTree(a);
    return 0;
}
