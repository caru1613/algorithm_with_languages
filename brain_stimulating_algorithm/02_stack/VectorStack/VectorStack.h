#ifndef __VECTORSTACK_H__
#define __VECTORSTACK_H__

#include <iostream>
#include <vector>

using namespace std;

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
}Node;


class VectorStack
{
    private:
        vector<ElementType> m_vectorNode;

    public:
        VectorStack();
        VectorStack(int capacity);
        ~VectorStack();
        void push(ElementType data);
        ElementType pop();
        bool isEmpty();
        void printData();
};

#endif
