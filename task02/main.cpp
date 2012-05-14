#include <iostream>
#include "fifo.h"

int main() {
    task02::FiFo *fifo = new task02::FiFo(3);

    for (int i = 0; i < 4; i++) {
        std::cout << "Pushing " << i << ": " << fifo->push(i) << std::endl;
    }

    for (int i = 0; i < 2; i++) {
        double d;
        const bool success = fifo->pop(d);
        std::cout << "Popping " << i << ": " << success << " got " << d << std::endl;
    }

    for (int i = 4; i < 7; i++) {
        std::cout << "Pushing " << i << ": " << fifo->push(i) << std::endl;
    }

    double *arr = new double[fifo->getCount()];

    fifo->getDataCopy(arr, fifo->getCount());

    for (unsigned int i = 0; i < fifo->getCount(); i++) {
        std::cout << "FiFo contains: " << arr[i] << std::endl;
    }

    std::cout << "Done" << std::endl;

    delete[] arr;
    delete fifo;

    return 0;
}
