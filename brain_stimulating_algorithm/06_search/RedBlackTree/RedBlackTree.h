#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

typedef int ElementType;

typedef struct tagRBTNode
{
    struct tagRBTNode* parent;
    struct tagRBTNode* left;
    struct tagRBTNode* right;

    enum { RED, BLACK } color;

    ElementType Data;

} RBTNode;


class RedBlackTree
{

};

#endif
