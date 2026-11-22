#include "queue.h"

#include <iostream>
#include <stdexcept>

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1;
}

bool isFullQueue(Queue Q) {
    return !isEmptyQueue(Q) && (Q.tail + 1) % 5 == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        throw std::overflow_error("queue penuh");
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % 5;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        throw std::underflow_error("queue kosong");
    }

    infotype x = Q.info[Q.head];
    if (Q.head == Q.tail) {
        CreateQueue(Q);
    } else {
        Q.head = (Q.head + 1) % 5;
    }
    return x;
}

void printInfo(Queue Q) {
    std::cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue";
    } else {
        for (int i = Q.head;; i = (i + 1) % 5) {
            std::cout << Q.info[i];
            if (i == Q.tail) {
                break;
            }
            std::cout << ' ';
        }
    }
    std::cout << '\n';
}
