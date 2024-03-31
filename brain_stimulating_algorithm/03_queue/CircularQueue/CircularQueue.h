#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

typedef int ElementType;

typedef struct tagNode 
{
    ElementType data;
}Node;

class CircularQueue
{
    private:
        Node* m_Node;
        int m_size;
        int m_head, m_tail;

    public:
        CircularQueue();
        CircularQueue(int capacity);
        ~CircularQueue();
        void Enqueue(ElementType data);
        ElementType Dequeue();
        void printQueue();
        int getSize();
        bool isEmpty();
        bool isFull();
};

#endif
