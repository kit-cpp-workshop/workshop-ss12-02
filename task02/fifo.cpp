/*
 * fifo.c
 *
 *  Created on: 03.04.2012
 *      Author: markus
 */

#include <algorithm>
#include "fifo.h"

namespace task02 {

    FiFo::FiFo(const size_t size) :
        size(size),
        count(0),
        readPos(0),
        data(new double[size]) {

    }

    FiFo::~FiFo() {
        delete[] data;
    }

    bool FiFo::push(const double &d) {
        bool result = (getRemaining() > 0);

        if (result) {
            data[(readPos + count++) % size] = d;
        }

        return result;
    }

    bool FiFo::pop(double &d) {
        bool result = (count > 0);

        if (result) {
            d = data[readPos++];

            readPos %= size;
            count--;
        }

        return result;
    }

    void FiFo::clear() {
        readPos = 0;
        count = 0;
    }

    size_t FiFo::getDataCopy(double *(&buffer), const size_t count) {
        size_t read = readPos;

        for (size_t i = 0; i < std::min(count, this->count); i++) {
            buffer[i] = data[read++];
            read %= size;
        }

        return this->count;
    }

    size_t FiFo::getSize() {
        return size;
    }

    size_t FiFo::getCount() {
        return count;
    }

    size_t FiFo::getRemaining() {
        return size - count;
    }

}
