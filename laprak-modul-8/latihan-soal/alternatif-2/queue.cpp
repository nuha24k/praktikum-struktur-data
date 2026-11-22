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
    return Q.head == 0 && Q.tail == 4;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        throw std::overflow_error("queue penuh");
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        if (Q.tail == 4) {
            int jumlah = Q.tail - Q.head + 1;
            for (int i = 0; i < jumlah; ++i) {
                Q.info[i] = Q.info[Q.head + i];
            }
            Q.head = 0;
            Q.tail = jumlah - 1;
        }
        ++Q.tail;
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
        ++Q.head;
    }
    return x;
}

void printInfo(Queue Q) {
    std::cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; ++i) {
            std::cout << Q.info[i] << (i == Q.tail ? "" : " ");
        }
    }
    std::cout << '\n';
}
