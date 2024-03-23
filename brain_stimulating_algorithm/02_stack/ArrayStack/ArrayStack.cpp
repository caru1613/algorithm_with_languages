
#include "ArrayStack.h"
#include <iostream>

using namespace std;

void ArrayStack::push(ElementType data)
{
    m_top++;
    m_node[m_top].data = data;
    cout << __func__ << " " << m_top << " " << m_node[m_top].data << endl;
}

ElementType ArrayStack::pop()
{
    ElementType ret = m_node[m_top].data;
    cout << __func__ << " " << m_top << " " << m_node[m_top].data << endl;
    m_top--;
    return ret;
}

int ArrayStack::getSize()
{
    cout << __func__ << " " << m_top+1 << endl;
    return m_top+1;;
}

bool ArrayStack::isEmpty()
{
    bool ret = (m_top == -1);
    cout << __func__ << " " << ret << endl;
    return ret;
}

void ArrayStack::printData()
{
    cout << __func__ << " " <<endl;
    for (int i = 0; i <= m_top; i++)
    {
        cout << "[" << i  << "]" << " " << m_node[i].data << endl;
    }
}

ArrayStack::ArrayStack()
    : m_capacity(0), m_top(-1), m_node(NULL)
{

}

ArrayStack::ArrayStack(int capacity)
    : m_capacity(capacity), m_top(-1)
{
    m_node = new Node[m_capacity];
    cout << __func__ << " " << m_capacity << " " << m_node << endl;
}

ArrayStack::~ArrayStack()
{
    cout << __func__ << " " << m_node << endl;
    if (m_node)
    {
        delete m_node;
    }
}
