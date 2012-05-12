/*
 * fifo.h
 *
 *  Created on: 03.04.2012
 *      Author: markus
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <cstddef>

namespace task02 {

    class FiFo {

    public:
        FiFo(const size_t size);
        virtual ~FiFo();

        bool push(const double &d);
        bool pop(double &d);
        void clear();

        double* getAll();

        size_t getSize();
        size_t getCount();
        size_t getFree();
    protected:
        const size_t size;
        size_t count;
        size_t readPos;

        double * const data;
    };

}

#endif /* FIFO_H_ */
