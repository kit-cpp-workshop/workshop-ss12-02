/*
 * fibo-lut.h
 *
 *  Created on: 12.05.2012
 *      Author: markus
 */

#ifndef FIBO_LUT_H_
#define FIBO_LUT_H_

namespace task01 {

    class FiboLUT {

    public:
        FiboLUT(const unsigned int maxFiboOrder);
        ~FiboLUT();

        unsigned long long get(const unsigned int number);

    private:
        const unsigned int tableSize;
        unsigned int lastValidBase;
        unsigned long long (* const table)[2];
    };

}

#endif /* FIBO_LUT_H_ */
