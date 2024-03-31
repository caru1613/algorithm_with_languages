
#include <iostream>
#include "LinkedListStack.h"
using namespace std;

LinkedListStack::LinkedListStack()
    : m_top(NULL), m_head(NULL), m_size(0)
{

}

LinkedListStack::~LinkedListStack()
{
    cout << __func__ << endl;
    while(!isEmpty())
    {
        cout << pop() << endl;
        cout << getSize() << endl;        
    }
}

void LinkedListStack::push(ElementType data)
{
    cout << __func__ << " " << data << endl;
    Node* pushNode = new Node();
    pushNode->data = data;

    if (m_head == NULL)
    {
        pushNode->prev = NULL;
        pushNode->next = NULL;
        m_head = pushNode;
    }
    else
    {
        pushNode->prev = m_top;
        pushNode->next = NULL;
        m_top->next = pushNode;
    }

    m_top = pushNode;
    m_size++;
}

ElementType LinkedListStack::pop()
{
    cout << __func__ << endl;
    ElementType popType;
    Node* popNode;

    if (m_top == m_head)
    {
        popNode = m_top;
        m_head = NULL;
        m_top = NULL;
    }
    else
    {
        popNode = m_top;
        m_top = m_top->prev;
        popNode->prev->next = NULL;
    }

    m_size--;

    popType = popNode->data;
    delete popNode;
    return popType;
}

void LinkedListStack::printData()
{
    Node *printNode = m_top;     
    
    cout << __func__ << endl;
    while(printNode != NULL)
    {
        cout << printNode->data << endl;
        printNode = printNode->prev; 
    }
}

int LinkedListStack::getSize()
{
    cout << __func__ << endl;
    return m_size;
}

int LinkedListStack::isEmpty()
{
    cout << __func__ << endl;
    return m_top == NULL;
}
