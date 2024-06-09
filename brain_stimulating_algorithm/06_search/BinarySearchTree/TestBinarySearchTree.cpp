#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

void printSearchResult(int searchTarget, BSTNode* result)
{
    if (result != NULL)
    {
        cout << "Found: " << result->data << endl;
    }
    else
    {
        cout << "Not Found: " << searchTarget << endl;
    }
}

int main(void)
{
    BinarySearchTree binarySearchTree;

    BSTNode* tree = binarySearchTree.createNode(123);
    BSTNode* node = NULL;

    binarySearchTree.insertNode(tree, binarySearchTree.createNode(22));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(9918));

    binarySearchTree.insertNode(tree, binarySearchTree.createNode(424));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(17));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(3));

    binarySearchTree.insertNode(tree, binarySearchTree.createNode(98));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(34));

    binarySearchTree.insertNode(tree, binarySearchTree.createNode(760));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(317));
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(1));

    int searchTarget = 17;
    node = binarySearchTree.searchNode(tree, searchTarget);
    printSearchResult(searchTarget, node);

    searchTarget = 117;
    node = binarySearchTree.searchNode(tree, searchTarget);
    printSearchResult(searchTarget, node);
    binarySearchTree.inorderPrintTree(tree);
    cout << endl;

    cout << "Removing 98..." << endl;
    node = binarySearchTree.removeNode(tree, NULL, 98);
    binarySearchTree.destroyNode(node);
    binarySearchTree.inorderPrintTree(tree);
    cout << endl;

    cout << "Inserting 111..." << endl;
    binarySearchTree.insertNode(tree, binarySearchTree.createNode(111));
    binarySearchTree.inorderPrintTree(tree);
    cout << endl;

    return 0;
}
