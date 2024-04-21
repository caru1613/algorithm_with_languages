#ifndef __LCRSTREE_H__
#define __LCRSTREE_H__

typedef char ElementType;

typedef struct tagCLRSNode
{
    struct tagLCRSNode* leftChild;
    struct tagLCRSNode* rightSibling;

    ElementType Data;

} LCRSNode;

class LCRSTree
{
    public:
        LCRSTree();
        ~LCRSTree();
        LCRSNode* createNode(ElementType data);
        void destroyNode(LCRSNode* node);
        void destroyTree();
        void addChildNode(LCRSNode* parent, LCRSNode* node);
        printTree();

    private:
        LCRSNode* m_rootNode;
};

#endif
