#include "SimpleBinaryTree.h"
#include <iostream>

using namespace std;

SBTNode* SimpleBinaryTree::createNode(ElementType data)
{
    SBTNode* newNode = new SBTNode;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    return newNode;
}

void SimpleBinaryTree::destroyNode(SBTNode* node)
{
    delete node;
}

void SimpleBinaryTree::destroyTree(SBTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    postorderPrintTree(node->left);
    postorderPrintTree(node->right);
    destroyNode(node);
}

void SimpleBinaryTree::preorderPrintTree(SBTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    cout << " " << node->data;

    preorderPrintTree(node->left);
    preorderPrintTree(node->right);
}

void SimpleBinaryTree::inorderPrintTree(SBTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    inorderPrintTree(node->left);

    cout << " " << node->data;

    inorderPrintTree(node->right);
}

void SimpleBinaryTree::postorderPrintTree(SBTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    postorderPrintTree(node->left);
    postorderPrintTree(node->right);
    cout << " " << node->data;
}

