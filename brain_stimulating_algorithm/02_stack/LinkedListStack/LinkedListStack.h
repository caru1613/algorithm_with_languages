#ifndef __LINKEDLISTSTACK_H__
#define __LINKEDLISTSTACK_H__

typedef int ElementType;

typedef struct tagNode
{
   ElementType data;
   struct tagNode* next;
   struct tagNode* prev;

}Node;

class LinkedListStack
{
    public:
        LinkedListStack();
        ~LinkedListStack();

        void push(ElementType data);
        ElementType pop();
        int getSize();
        int isEmpty();
        void printData();

    private:
        Node* m_top;
        Node* m_head;
        int m_size;
};

#endif
