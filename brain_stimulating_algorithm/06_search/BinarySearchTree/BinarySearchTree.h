#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

typedef int ElementType;

typedef struct tagBSTNode
{
    struct tagBSTNode* left;
    struct tagBSTNode* right;

    ElementType data;
} BSTNode;

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        BSTNode* createNode(ElementType newData);
        void destroyNode(BSTNode* node);
        void destroyTree(BSTNode* tree);

        BSTNode* searchNode(BSTNode* tree, ElementType target);
        BSTNode* searchMinNode(BSTNode* tree);
        void insertNode(BSTNode* tree, BSTNode* child);
        BSTNode* removeNode(BSTNode* tree, BSTNode* parent, ElementType target);
        void inorderPrintTree(BSTNode* node);

    private:
        BSTNode* root;
};

#endif
