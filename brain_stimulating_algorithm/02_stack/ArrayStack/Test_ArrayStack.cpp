#include "ArrayStack.h"
#include <iostream>

using namespace std;

int main()
{
    ArrayStack arrayStack(10);

    arrayStack.isEmpty();

    arrayStack.push(5);
    arrayStack.push(3);
    arrayStack.push(1);
    arrayStack.push(4);
    arrayStack.push(2);

    arrayStack.isEmpty();
    arrayStack.printData();

    arrayStack.pop();
    arrayStack.pop();
    arrayStack.pop();

    arrayStack.isEmpty();
    arrayStack.printData();

    arrayStack.push(6);
    arrayStack.push(7);
    arrayStack.push(8);

    arrayStack.isEmpty();
    arrayStack.printData();

}
