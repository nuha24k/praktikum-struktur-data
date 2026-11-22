#include <cassert>
#include <stdexcept>

#include "queue.h"

int main() {
    Queue Q;
    CreateQueue(Q);
    assert(isEmptyQueue(Q));

    for (int i = 1; i <= 5; ++i) {
        enqueue(Q, i);
    }
    assert(isFullQueue(Q));
    assert(dequeue(Q) == 1);
    enqueue(Q, 6);

    for (int i = 2; i <= 6; ++i) {
        assert(dequeue(Q) == i);
    }
    assert(isEmptyQueue(Q));

    try {
        dequeue(Q);
        assert(false);
    } catch (const std::underflow_error &) {
    }
}
