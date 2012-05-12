/*
 * fibo-lut.cpp
 *
 *  Created on: 12.05.2012
 *      Author: markus
 */

#include <algorithm>
#include "fibo-lut.h"

namespace task01 {

    static void fiboCalculate(unsigned long long (&lastFibos)[2], unsigned int first, unsigned int count);

    FiboLUT::FiboLUT(const unsigned int tableSize) :
        tableSize(std::max(tableSize / spacingScale, (unsigned int) 1) * 2),
        lastValidBase(0),
        table(new unsigned long long[tableSize][2]) {

        // assert table != NULL

        table[0][0] = 0;
        table[0][1] = 1;
    }

    FiboLUT::~FiboLUT() {
        delete[] table;
    }

    unsigned long long FiboLUT::get(const unsigned int number) {
        const unsigned int requestedBase = number / spacingScale;
        const unsigned int availableBase = std::min(requestedBase, lastValidBase);

        // setup base fibos
        unsigned long long lastFibos[2] = {
                table[availableBase][0],
                table[availableBase][1]
        };

        // extend base if required
        unsigned int base;
        for (base = availableBase + 1; base < std::min(tableSize, requestedBase + 1); base++) {
            fiboCalculate(lastFibos, base * spacingScale + 2, spacingScale);

            table[base][0] = lastFibos[0];
            table[base][1] = lastFibos[1];
        }
        lastValidBase = --base;

        // calculate fibos from base to number
        if (base * spacingScale + 1 < number) {
            fiboCalculate(lastFibos, base * spacingScale + 2, number - base * spacingScale - 1);
        }

        return lastFibos[number & 0x1];
    }

    // calculates fibo first + count - 1 using first - 1 and first - 2
    void fiboCalculate(unsigned long long (&lastFibos)[2],
            unsigned int first, unsigned int count) {
        for (unsigned int i = first; i < first + count; i++) {
            const long long newFibo = lastFibos[0] + lastFibos[1];

            lastFibos[i & 0x1] = newFibo;
        }
    }

}
