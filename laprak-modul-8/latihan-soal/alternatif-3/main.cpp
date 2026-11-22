#include <iostream>

#include "queue.h"

int main() {
    Queue Q;
    CreateQueue(Q);

    std::cout << "H - T\t| Queue Info\n";
    std::cout << "--------------------\n";
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
}
