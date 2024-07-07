#include "RedBlackTree.h"
#include <cstring>
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree()
{
    Nil = createNode(0);
    Nil->color = BLACK;
}

RedBlackTree::~RedBlackTree()
{
    destroyNode(Nil);
}

RBTNode* RedBlackTree::getNil(void)
{
    return Nil;
}

void RedBlackTree::destroyTree(RBTNode* tree)
{
    if (tree->right != Nil)
    {
        destroyTree(tree->right);
    }

    if (tree->left != Nil)
    {
        destroyTree(tree->left);
    }

    tree->left = Nil;
    tree->right = Nil;

    destroyNode(tree);
}

RBTNode* RedBlackTree::createNode(ElementType newData)
{
    RBTNode* newNode = new RBTNode;

    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    newNode->color = BLACK;

    return newNode;
}

void RedBlackTree::destroyNode(RBTNode* node)
{
    delete node;
}

RBTNode* RedBlackTree::searchNode(RBTNode* tree, ElementType target)
{
    if (tree == Nil)
    {
        return NULL;
    }

    if (tree->data > target)
    {
        return searchNode(tree->left, target);
    }
    else if (tree->data < target)
    {
        return searchNode(tree->right, target);
    }

    return tree;
}

RBTNode* RedBlackTree::searchMinNode(RBTNode* tree)
{
    if (tree == Nil)
    {
        return Nil;
    }

    if (tree->left == Nil)
    {
        return tree;
    }

    return searchMinNode(tree->left);
}

void RedBlackTree::insertNode(RBTNode** tree, RBTNode* newNode)
{
    insertNodeHelper(tree, newNode);

    newNode->color = RED;
    newNode->left = Nil;
    newNode->right = Nil;

    rebuildAfterInsert(tree, newNode);
}

void RedBlackTree::insertNodeHelper(RBTNode** tree, RBTNode* newNode)
{
    if ((*tree) == NULL)
    {
        (*tree) = newNode;
    }

    if ((*tree)->data < newNode->data)
    {
        if ( (*tree)->right == Nil)
        {
            (*tree)->right = newNode;
            newNode->parent = (*tree);
        }
        else
        {
            insertNodeHelper(&(*tree)->right, newNode);
        }
    }
    else if ( (*tree)->data > newNode->data)
    {
        if ((*tree)->left == Nil)
        {
            (*tree)->left = newNode;
            newNode->parent = (*tree);
        }
    }
    else
    {
        insertNodeHelper(&(*tree)->left, newNode);
    }
}

RBTNode* RedBlackTree::removeNode(RBTNode** root, ElementType target)
{

    return NULL;
}

void RedBlackTree::rebuildAfterInsert(RBTNode** tree, RBTNode* newNode)
{
    while (newNode != (*tree) && newNode->parent->color == RED)
    {
        if (newNode->parent == newNode->parent->parent->left)
        {
            RBTNode* uncle = newNode->parent->parent->right;

            if (uncle->color == RED)
            {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;

                newNode = newNode->parent->parent;
            }
            else
            {
                if (newNode == newNode->parent->right)
                {
                    newNode = newNode->parent;
                    rotateLeft(tree, newNode);
                }

                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rotateRight(tree, newNode->parent->parent);
            }
        }
        else
        {
            RBTNode* uncle = newNode->parent->parent->left;

            if (uncle->color == RED)
            {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;

                newNode = newNode->parent->parent;
            }
            else
            {
                if (newNode == newNode->parent->left)
                {
                    newNode = newNode->parent;
                    rotateRight(tree, newNode);
                }

                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rotateLeft(tree, newNode->parent->parent);
            }
        }
    }

    (*tree)->color = BLACK;
}

void RedBlackTree::rebuildAfterRemove(RBTNode** root, RBTNode* successor)
{
    RBTNode* sibling = NULL;

    while ( successor->parent != NULL && successor->color == BLACK)
    {
        if ( successor == successor->parent->left )
        {
            sibling = successor->parent->right;

            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateLeft(root, successor->parent);
            }
            else
            {
                if (sibling->left->color == BLACK && sibling->right->color == BLACK)
                {
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else
                {
                    if (sibling->left->color == RED)
                    {
                        sibling->left->color = BLACK;
                        sibling->color = RED;

                        rotateRight(root, sibling);
                        sibling = successor->parent->right;
                    }

                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(root, successor->parent);
                    successor = (*root);
                }
            }
        }
        else
        {
            sibling = successor->parent->left;

            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateRight(root, successor->parent);
            }
            else
            {
                if (sibling->right->color == BLACK &&
                    sibling->left->color == BLACK)
                {
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else
                {
                    if (sibling->right->color == RED)
                    {
                        sibling->right->color = BLACK;
                        sibling->color = RED;

                        rotateLeft(root, sibling);
                        sibling = successor->parent->left;
                    }

                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(root, successor->parent);
                    successor = (*root);
                }
            }
        }
    }

    successor->color = BLACK;
}

void RedBlackTree::printTree(RBTNode* node, int depth, int blackCount)
{
    int i = 0;
    char c = 'X';
    int v = -1;
    char cnt[100];

    if (node == NULL || node == Nil)
    {
        return;
    }

    if (node->color == BLACK)
    {
        blackCount++;
    }

    if (node->parent != NULL)
    {
        v = node->parent->data;

        if (node->parent->left == node)
        {
            c = 'L';
        }
        else
        {
            c = 'R';
        }
    }

    if (node->left == Nil && node->right == Nil)
    {
        cout << "---------- " << blackCount;
    }
    else
    {
        strncpy(cnt, "", sizeof(cnt));        
    }

    for (i = 0; i < depth; i++)
    {
        cout <<"  ";
    }

    string color = (node->color == RED)?"RED":"BLACK";
    cout << node->data << " " << color << "[" << c << "," << v << "]" << " " << cnt << endl;

    printTree(node->left, depth+1, blackCount);
    printTree(node->right, depth+1, blackCount);
}

void RedBlackTree::rotateLeft(RBTNode** root, RBTNode* parent)
{
    RBTNode* rightChild = parent->right;

    parent->right = rightChild->left;

    if (rightChild->left != Nil)
    {
        rightChild->left->parent = parent;
    }

    rightChild->parent = parent->parent;

    if ( parent->parent == NULL )
    {
        (*root) = rightChild;
    }
    else
    {
        if (parent == parent->parent->left)
        {
            parent->parent->left = rightChild;
        }
        else
        {
            parent->parent->right = rightChild;
        }
    }

    rightChild->left = parent;
    parent->parent = rightChild;
}

void RedBlackTree::rotateRight(RBTNode** root, RBTNode* parent)
{
    RBTNode* leftChild = parent->left;

    parent->left = leftChild->right;

    if (leftChild->right != Nil)
    {
        leftChild->right->parent = parent;
    }

    leftChild->parent = parent->parent;

    if (parent->parent == NULL)
    {
        (*root) = leftChild;
    }
    else
    {
        if (parent == parent->parent->left)
        {
            parent->parent->left = leftChild;
        }
        else
        {
            parent->parent->right = leftChild;
        }
    }

    leftChild->right = parent;
    parent->parent = leftChild;
}
