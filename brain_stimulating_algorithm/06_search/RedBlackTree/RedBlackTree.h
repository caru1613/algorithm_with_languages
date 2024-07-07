#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

typedef int ElementType;

typedef enum { RED, BLACK } Color;

typedef struct tagRBTNode
{
    struct tagRBTNode* parent;
    struct tagRBTNode* left;
    struct tagRBTNode* right;

    ElementType data;
    Color color;

} RBTNode;

class RedBlackTree
{
    public:
        RedBlackTree();
        ~RedBlackTree();
        void destroyTree(RBTNode* tree);
        RBTNode* createNode(ElementType newData);
        void destroyNode(RBTNode* node);
        RBTNode* searchNode(RBTNode* tree, ElementType target);
        RBTNode* searchMinNode(RBTNode* tree);
        void insertNode(RBTNode** tree, RBTNode* newNode);
        void insertNodeHelper(RBTNode** tree, RBTNode* newNode);
        RBTNode* removeNode(RBTNode** root, ElementType target);
        void rebuildAfterInsert(RBTNode** tree, RBTNode* newNode);
        void rebuildAfterRemove(RBTNode** root, RBTNode* successor);
        void printTree(RBTNode* node, int depth, int blackCount);
        void rotateLeft(RBTNode** root, RBTNode* parent);
        void rotateRight(RBTNode** root, RBTNode* parent);

        RBTNode* getNil(void);
    private:
        RBTNode* Nil;
};

#endif
