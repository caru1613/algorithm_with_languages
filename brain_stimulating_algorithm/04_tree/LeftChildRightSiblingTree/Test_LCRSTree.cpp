#include "LCRSTree.h"

int main(void)
{
    LCRSTree lcrsTree;

    LCRSNode* root = lcrsTree.createNode('A');
    LCRSNode* b = lcrsTree.createNode('B');
    LCRSNode* c = lcrsTree.createNode('C');
    LCRSNode* d = lcrsTree.createNode('D');
    LCRSNode* e = lcrsTree.createNode('E');
    LCRSNode* f = lcrsTree.createNode('F');
    LCRSNode* g = lcrsTree.createNode('G');
    LCRSNode* h = lcrsTree.createNode('H');
    LCRSNode* i = lcrsTree.createNode('I');
    LCRSNode* j = lcrsTree.createNode('J');
    LCRSNode* k = lcrsTree.createNode('K');

    lcrsTree.addChildNode(root, b);
        lcrsTree.addChildNode(b, c);
        lcrsTree.addChildNode(b, d);
            lcrsTree.addChildNode(d, e);
            lcrsTree.addChildNode(d, f);

    lcrsTree.addChildNode(root, g);
        lcrsTree.addChildNode(g, h);

    lcrsTree.addChildNode(root, i);
        lcrsTree.addChildNode(i, j);
            lcrsTree.addChildNode(j, k);

    lcrsTree.printTree(root, 0);

    lcrsTree.destroyTree(root);
    
    return 0;
}
