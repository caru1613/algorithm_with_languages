
typedef char ElementType;

typedef struct tagSBTNode
{
    struct tagSBTNode* left;
    struct tagSBTNode* right;

    ElementType data;
} SBTNode;

class SimpleBinaryTree
{
    public:
        SBTNode* createNode(ElementType data);
        void destroyNode(SBTNode* node);
        void destroyTree(SBTNode* node);
        void preorderPrintTree(SBTNode* node);
        void inorderPrintTree(SBTNode* node);
        void postorderPrintTree(SBTNode* node);

    private:
        SBTNode* root;

};
