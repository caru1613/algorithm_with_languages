#include <iostream>
#include "VectorStack.h"

using namespace std;

int main()
{

    VectorStack vectorStack;

    vectorStack.push(10);
    vectorStack.push(9);
    vectorStack.push(8);
    vectorStack.push(7);
    vectorStack.push(6);

    vectorStack.printData();

    cout << vectorStack.pop() << endl;
    cout << vectorStack.pop() << endl;
    cout << vectorStack.pop() << endl;
    cout << vectorStack.pop() << endl;

    vectorStack.printData();

    vectorStack.push(5);
    vectorStack.push(4);
    vectorStack.push(3);

    vectorStack.printData();

    cout << vectorStack.pop() << endl;
    cout << vectorStack.pop() << endl;

    vectorStack.printData();

    return 0;
}
