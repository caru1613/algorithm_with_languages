#include <iostream>
#include "LinkedListStack.h"

using namespace std;
int main()
{
    LinkedListStack linkedListStack;

    linkedListStack.push(10);
    linkedListStack.push(9);
    linkedListStack.push(8);
    linkedListStack.push(7);

    linkedListStack.printData();

    cout << linkedListStack.pop() << endl;
    cout << linkedListStack.pop() << endl;
    cout << linkedListStack.pop() << endl;

    linkedListStack.push(6);
    linkedListStack.push(5);
    linkedListStack.push(4);

    cout << linkedListStack.pop() << endl;
    cout << linkedListStack.pop() << endl;

    linkedListStack.printData();
    return 0;
}
