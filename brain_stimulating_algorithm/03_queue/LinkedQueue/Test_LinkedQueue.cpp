#include "LinkedQueue.h"

int main()
{
    LinkedQueue queue;

    queue.Enqueue(10);
    queue.Enqueue(9);
    queue.Enqueue(8);
    queue.Enqueue(7);

    queue.PrintQueue();

    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    queue.PrintQueue();

    queue.Enqueue(6);
    queue.Enqueue(5);
    queue.Enqueue(4);

    queue.PrintQueue();

    queue.Dequeue();
    queue.Dequeue();

    queue.PrintQueue();

    return 0;
}
