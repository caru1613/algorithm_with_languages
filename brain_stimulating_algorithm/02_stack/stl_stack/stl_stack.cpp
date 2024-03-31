#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(9);
    st.push(8);
    st.push(7);

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    st.push(6);
    st.push(5);
    st.push(4);

    cout << st.top() << endl;
    st.pop();

    cout << st.top() << endl;
    st.pop();

    cout << "Clean the rest up." << endl;
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}
