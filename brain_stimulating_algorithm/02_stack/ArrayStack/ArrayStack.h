#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
}Node;


class ArrayStack
{
    private:
        int m_capacity;
        int m_top;
        Node* m_node;

    public:
        ArrayStack();
        ~ArrayStack();
        ArrayStack(int capacity);
        void push(ElementType data);
        ElementType pop();
        int getSize();
        bool isEmpty();
        void printData();
};

#endif
