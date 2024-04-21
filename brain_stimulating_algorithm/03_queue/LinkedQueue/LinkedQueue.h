#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
    struct tagNode* next;
}Node;

class LinkedQueue
{
    private:
        Node* m_Front;
        Node* m_Rear;
        unsigned int m_size;

    public:
        LinkedQueue();
        ~LinkedQueue();
        void Enqueue(ElementType data);
        ElementType Dequeue();
        void PrintQueue();
        int getSize();
        bool isEmpty();
};

#endif
