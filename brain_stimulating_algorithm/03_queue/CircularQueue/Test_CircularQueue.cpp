#include <iostream>
#include "CircularQueue.h"

int main()
{
    CircularQueue circularQueue(5);
    ElementType val;

    circularQueue.Enqueue(10);
    circularQueue.Enqueue(9);
    circularQueue.Enqueue(8);
    circularQueue.Enqueue(7);

    circularQueue.printQueue();

    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();

    circularQueue.printQueue();

    circularQueue.Enqueue(6);
    circularQueue.Enqueue(5);
    circularQueue.Enqueue(4);
    circularQueue.Enqueue(3);
    circularQueue.Enqueue(2);

    circularQueue.printQueue();

    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();
    val = circularQueue.Dequeue();

    circularQueue.printQueue();
    return 0;
}
