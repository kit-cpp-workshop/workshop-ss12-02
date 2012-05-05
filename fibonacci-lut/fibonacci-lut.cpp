/*
 * fibonacci-lut.cpp
 *
 *  Created on: 05.05.2012
 *      Author: prime
 */


#include <iostream>
#include <vector>

class FibonacciLookupTable {
public:
	FibonacciLookupTable(unsigned int number_of_elements);
	~FibonacciLookupTable();

	void get_fibo_series(); //prints the whole fibo series !!get->print ersetzen oder array zurückgeben
	unsigned int get_fibo_at(int n); //prints specific fibo, the nth fibo


private:
	unsigned int *first_fibo_ptr;
};

FibonacciLookupTable::FibonacciLookupTable(unsigned int number_of_elements) {
	first_fibo_ptr = new unsigned int[number_of_elements];
	unsigned int n_minus = 0;
	unsigned int n = 1;
	unsigned int n_plus;

	*first_fibo_ptr = 0;
	*(first_fibo_ptr + 1) = 1;

	for (unsigned int i=2; i<number_of_elements; ++i) {

		n_plus = n_minus + n;
		*(first_fibo_ptr + i) = n_plus;
		n_minus = n;
		n = n_plus;
	}
}

FibonacciLookupTable::~FibonacciLookupTable() {
	delete[] first_fibo_ptr;
	first_fibo_ptr = 0;
}

void FibonacciLookupTable::get_fibo_series() {

}

unsigned int FibonacciLookupTable::get_fibo_at(int n) {
	return  (*(first_fibo_ptr + n));
}



int main() {
	FibonacciLookupTable LUT(10);
	unsigned int an_element;
	std::cout << "Das wievielte Element?: ";
	std::cin >> an_element;
	std::cout << LUT.get_fibo_at(an_element);
}
