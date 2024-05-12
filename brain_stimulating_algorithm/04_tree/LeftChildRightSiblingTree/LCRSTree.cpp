#include "LCRSTree.h"
#include <iostream>

using namespace std;

LCRSTree::LCRSTree()
    :m_rootNode(NULL)
{
 
}

LCRSTree::~LCRSTree()
{

}

LCRSNode* LCRSTree::createNode(ElementType data)
{
    LCRSNode * NewNode = new LCRSNode;
    NewNode->leftChild = NULL;
    NewNode->rightSibling = NULL;
    NewNode->data = data;

    return NewNode;
}

void LCRSTree::destroyNode(LCRSNode* node)
{
    delete node;
}

void LCRSTree::destroyTree(LCRSNode* root)
{
    if (root->rightSibling != NULL)
    {
        destroyTree((LCRSNode*)root->rightSibling);
    }

    if (root->leftChild != NULL)
    {
        destroyTree((LCRSNode*)root->leftChild);
    }

    root->leftChild = NULL;
    root->rightSibling = NULL;
    destroyNode(root);
}

void LCRSTree::addChildNode(LCRSNode* parent, LCRSNode* child)
{
    if (parent->leftChild == NULL)
    {
        parent->leftChild = (LCRSNode*)child;
    }
    else
    {
        LCRSNode* TempNode = (LCRSNode*)parent->leftChild;
        while (TempNode->rightSibling != NULL)
            TempNode = TempNode->rightSibling;

        TempNode->rightSibling = child;
    }
}

void LCRSTree::printTree(LCRSNode* node, int depth)
{
    int i=0;

    for (i = 0; i < depth-1; i++)
        cout << "   ";

    if (depth > 0)
        cout << "+--";

    cout << node->data << endl;

    if (node->leftChild != NULL)
    {
        printTree((LCRSNode*)node->leftChild, depth+1);
    }

    if (node->rightSibling != NULL)
    {
        printTree((LCRSNode*)node->rightSibling, depth);
    }
}

