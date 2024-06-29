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
    public:
        RedBlackTree();
        ~RedBlackTree();
        void DestroyTree(RBTNode* tree);
        RBTNode* CreateNode(ElementType newData);
        void DestroyNodee(RBTNode* node);
        RBTNode* SearchNode(RBTNode* tree, ElementType target);
        RBTNode* SearchMinNode(RBTNode* tree);
        void InsertNode(RBTNode** tree, RBTNode* newNode);
        void InsertNodeHelper(RBTNode** tree, RBTNode* newNode);
        RBTNode* RemoveNode(RBTNode** root, ElementType target);
        void RebuildAfterInsert(RBTNode** tree, RBTNode* newNode);
        void RebuildAfterRemove(RBTNode** root, RBTNode* x);
        void PrintTree(RBTNode* node, int depth, int blackCount);
        void RotateLeft(RBTNode** root, RBTNode* parent);
        void RotateRight(RBTNode** root, RBTNode* parent);
};

#endif
