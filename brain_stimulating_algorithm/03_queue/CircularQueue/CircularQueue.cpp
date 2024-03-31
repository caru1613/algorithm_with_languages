#include "CircularQueue.h"
#include <iostream>

using namespace std;

CircularQueue::CircularQueue()
    : m_Node(NULL), m_size(0), m_head(0), m_tail(0)
{
    cout << __func__ << endl;
}

CircularQueue::CircularQueue(int capacity)
    : m_head(0), m_tail(0)
{
    cout << __func__ << " " << capacity << endl;

    m_Node = new Node[capacity];
    m_size = capacity;
}

CircularQueue::~CircularQueue()
{
    cout << __func__ << endl;

    if (m_Node)
    {
        delete m_Node;
    }
}

void CircularQueue::Enqueue(ElementType data)
{
    cout << __func__ << " " << data << endl;

    if (m_Node && !isFull())
    {
        m_head = (m_head + 1) % (m_size);
        m_Node[m_head].data = data;        
    }
    else
    {
        cout << "No Enqueue data" << endl;
    }
}

ElementType CircularQueue::Dequeue()
{
    cout << __func__ << endl;

    ElementType retElement = 0;

    if (m_Node && !isEmpty())
    {
        m_tail = (m_tail + 1) % m_size;
        retElement = m_Node[m_tail].data;
    }
    else
    {
        cout << "No Dequeue data" << endl;
    }

    return retElement;
}

void CircularQueue::printQueue()
{
    cout << __func__ << " " << m_head << " " << m_tail << endl;

    int loop = m_tail+1;

    if (isEmpty())
    {
        cout << "No data" << endl;
        return;
    }
        
    while (loop != m_head)
    {
        cout << m_Node[loop].data << " " ;
        loop = (loop + 1) % m_size;
    }

    cout << m_Node[loop].data << " " ;

    cout << endl;
}

int CircularQueue::getSize()
{
    cout << __func__ << " " << m_size << endl;
    
    return m_size;
}

bool CircularQueue::isEmpty()
{
    cout << __func__ << " " << (m_head == m_tail) << endl; 
    return m_head == m_tail;
}

bool CircularQueue::isFull()
{
    cout << __func__ << " " << (((m_head + 1) % m_size) == m_tail) << endl; 
    return ((m_head + 1) % m_size) == m_tail;
}
