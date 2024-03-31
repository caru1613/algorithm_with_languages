#include <vector>
#include <iostream>
#include "VectorStack.h"

using namespace std;

VectorStack::VectorStack()
{
    cout << __func__ << endl;
}

VectorStack::~VectorStack()
{
    cout << __func__ << endl;
}

VectorStack::VectorStack(int capacity)
{
    cout << __func__ << " " << capacity << endl;
    m_vectorNode.reserve(capacity);
}

void VectorStack::push(ElementType data)
{
    cout << __func__ << " " << data << endl;
    m_vectorNode.push_back(data);
}

ElementType VectorStack::pop()
{
    cout << __func__ << endl;

    if (m_vectorNode.empty() )
    {
        cout << "No data in stack." << endl;
        return 0;
    }
    //ElementType retNode = m_vectorNode[m_vectorNode.size()-1];
    
    ElementType retNode = m_vectorNode.back();
    m_vectorNode.pop_back();

    return retNode;
}

bool VectorStack::isEmpty()
{
    cout << __func__ << endl;
    return m_vectorNode.empty();
}

void VectorStack::printData()
{   
   cout << __func__ << endl;

#if 0
   for(vector<ElementType>::iterator iter = m_vectorNode.begin(); iter != m_vectorNode.end(); ++iter)
   {
      cout << *iter << endl;
   } 
#else
   for(vector<ElementType>::reverse_iterator riter = m_vectorNode.rbegin(); riter != m_vectorNode.rend(); ++riter)
   {
      cout << *riter << endl;
   }
#endif

}
