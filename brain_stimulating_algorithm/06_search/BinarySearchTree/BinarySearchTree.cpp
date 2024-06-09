#include "BinarySearchTree.h"
#include <iostream>

using namespace std;
BinarySearchTree::BinarySearchTree()
{

}

BinarySearchTree::~BinarySearchTree()
{

}

BSTNode* BinarySearchTree::createNode(ElementType newData)
{
    BSTNode* newNode = new BSTNode;

    newNode->left = NULL;
    newNode->right =NULL;
    newNode->data = newData;

    return newNode;
}

void BinarySearchTree::destroyNode(BSTNode* node)
{
    if(node)
    {
        delete node;
    }
}

void BinarySearchTree::destroyTree(BSTNode* tree)
{
    if (tree->right != NULL)
    {
        destroyTree( tree->right);
    }

    if (tree->left != NULL)
    {
        destroyTree(tree->left);
    }

    tree->left = NULL;
    tree->right = NULL;

    destroyNode(tree);
}

BSTNode* BinarySearchTree::searchNode(BSTNode* tree, ElementType target)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->data == target)
    {
        return tree;
    }
    else if ( tree->data > target)
    {
        return searchNode(tree->left, target);
    }
    else
    {
        return searchNode(tree->right, target);
    }

    /* It never happens */
    return NULL;
}

/* Search minimum value in Tree */
BSTNode* BinarySearchTree::searchMinNode(BSTNode* tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->left == NULL)
    {
        return tree;
    }
    else
    {
        return searchMinNode(tree->left);
    }

    return searchMinNode(tree->left);
}

void BinarySearchTree::insertNode(BSTNode* tree, BSTNode* child)
{
    if (tree->data < child->data)
    {
        if (tree->right == NULL)
        {
            tree->right = child;
        }
        else
        {
            insertNode(tree->right, child);
        }
    }
    else if (tree->data > child->data)
    {
        if (tree->left == NULL)
        {
            tree->left = child;
        }
        else
        {
            insertNode(tree->left, child);
        }
    }
}

BSTNode* BinarySearchTree::removeNode(BSTNode* tree, BSTNode* parent, ElementType target)
{
    BSTNode* removed = NULL;

    if (tree == NULL)
    {
        return NULL;
    }

    if (tree->data > target)
    {
        removed = removeNode(tree->left, tree, target);
    }
    else if (tree->data < target)
    {
        removed = removeNode(tree->right, tree, target);
    }
    else
    {
        removed = tree;
        if (tree->left == NULL && tree->right == NULL)
        {
           if (parent->left == tree)
           {
              parent->left = NULL;
           }
           else
           {
              parent->right = NULL;
           } 
        } 
        else
        {
            if (tree->left != NULL && tree->right != NULL)
            {
                BSTNode* minNode = searchMinNode(tree->right);
                minNode = removeNode(tree, NULL, minNode->data);
                tree->data = minNode->data;
            }
            else
            {
                BSTNode* temp = NULL;
                if (tree->left != NULL)
                {
                    temp = tree->left;
                }
                else
                {
                    temp = tree->right;
                }

                if (parent->left == tree)
                {
                    parent->left = temp;
                }
                else
                {
                    parent->right = temp;
                }
            }
        }
    }

    return removed;
}

void BinarySearchTree::inorderPrintTree(BSTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    inorderPrintTree(node->left);
    cout << node->data << " ";
    inorderPrintTree(node->right);
}
