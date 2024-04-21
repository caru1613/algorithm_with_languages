#include "LinkedQueue.h"
#include <iostream>

using namespace std;

LinkedQueue::LinkedQueue()
    :m_Front(NULL), m_Rear(NULL)
{
    cout << __func__ << endl;
}

LinkedQueue::~LinkedQueue()
{
    cout << __func__ << endl;

    while (!isEmpty())
    {
        Dequeue();
    }
}

void LinkedQueue::Enqueue(ElementType data)
{
    if (isEmpty())
    {
        m_Front = new Node();
        m_Front->next = NULL;
        m_Front->data = data;
        m_Rear = m_Front;
    }
    else
    {
        Node* insNode = new Node();
        insNode->data = data;

        m_Rear->next = insNode;
        insNode->next = NULL;

        m_Rear = insNode;
    }
    m_size++;

    cout << __func__ << " " << data << endl;
}

ElementType LinkedQueue::Dequeue()
{
    ElementType delElement = 0;
    Node* delNode;
    if (!isEmpty())
    {
        delNode = m_Front;
        delElement = delNode->data;
        
        m_Front = m_Front->next;

        delete delNode;
        m_size--;
    }

    cout << __func__ << " " << delElement << endl;
    return delElement;
}

void LinkedQueue::PrintQueue()
{
    cout << __func__ << endl;
    Node* printNode = m_Front;

    while(printNode)
    {
        cout << printNode->data << " ";
        printNode = printNode->next;
    }
    cout << endl;
}    

int LinkedQueue::getSize()
{
    return m_size;
}

bool LinkedQueue::isEmpty()
{
    return (m_Front == NULL);
}
