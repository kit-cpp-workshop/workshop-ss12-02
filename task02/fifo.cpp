/*
 * fifo.c
 *
 *  Created on: 03.04.2012
 *      Author: markus
 */

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
        bool result = (getFree() > 0);

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

    double* FiFo::getAll() {
        double *result = new double[count];

        size_t read = readPos;
        for (size_t i = 0; i < count; i++) {
            result[i] = data[read++];
            read %= size;
        }

        return result;
    }

    size_t FiFo::getSize() {
        return size;
    }

    size_t FiFo::getCount() {
        return count;
    }

    size_t FiFo::getFree() {
        return size - count;
    }

}
