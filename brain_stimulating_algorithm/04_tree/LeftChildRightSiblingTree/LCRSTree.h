#ifndef __LCRSTREE_H__
#define __LCRSTREE_H__

typedef char ElementType;

typedef struct tagLCRSNode
{
    struct tagLCRSNode* leftChild;
    struct tagLCRSNode* rightSibling;

    ElementType data;

} LCRSNode;

class LCRSTree
{
    public:
        LCRSTree();
        ~LCRSTree();
        LCRSNode* createNode(ElementType data);
        void destroyNode(LCRSNode* node);
        void destroyTree(LCRSNode* root);
        void addChildNode(LCRSNode* parent, LCRSNode* child);
        void printTree(LCRSNode* node, int depth);

    private:
        LCRSNode* m_rootNode;
};

#endif
