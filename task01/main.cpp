/*
 * main.c
 *
 *  Created on: 12.05.2012
 *      Author: markus
 */

#include <iostream>
#include "fibo-lut.h"

void compare(unsigned int index, unsigned long long expected, unsigned long long got) {
    if (expected != got) {
        std::cout << "Error at index: " << index << " expected " << expected << " got " << got << std::endl;
    }
}

int main() {
    task01::FiboLUT * const fibo = new task01::FiboLUT(200000);

    unsigned long long lastFibos[2] = { 0, 1 };
    unsigned int i;

    // Easy case: first two fibos
    for (i = 0; i < 2 && i < 2; i++) {
        compare(i, lastFibos[i], fibo->get(i));
    }

    // This case is easy, too
    for (; i < 100000; i++) {
        const unsigned long long newFibo = lastFibos[0] + lastFibos[1];

        lastFibos[i & 0x1] = newFibo;

        compare(i, newFibo, fibo->get(i));
    }

    std::cout << "All done" << std::endl;

    return 0;
}
