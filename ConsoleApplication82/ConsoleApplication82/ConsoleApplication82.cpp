#include <iostream>
#include <conio.h>
#include "Stack.cpp"
#include "Queue.cpp"

void StackTest()
{
    Stack<char> stack;
    char c;

    stack.MAKENULL();
    c = _getch();
    while (c != '=')
    {
        switch (c)
        {
        case '#': stack.POP(); break;
        case '@': stack.MAKENULL(); break;
        case '^': stack.PUSH(stack.TOP()); break;
        default: stack.PUSH(c); break;
        }
        c = _getch();
    }
    stack.PRINT();
}

void QueueTest()
{
    Queue<char> queue;
    char c;

    queue.MAKENULL();
    c = _getch();
    while (c != '='){
        queue.ENQUEUE(c);
        c = _getch();
    }

    queue.DEQUEUE();
    queue.DEQUEUE();
    queue.ENQUEUE('<');

    while (!queue.EMPTY())
    {
        printf("%c, ", queue.FRONT());
        queue.DEQUEUE();
    }
    printf("\n");
}

int main()
{
    StackTest();
    QueueTest();
    return 0;
}
