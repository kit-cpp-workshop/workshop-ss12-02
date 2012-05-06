/*
 * fibonacci-lut.cpp
 *
 *  Created on: 05.05.2012
 *      Author: prime
 */


#include <iostream>
#include <cmath>

class FibonacciLookupTable {
public:
	FibonacciLookupTable(unsigned int number_of_elements);
	~FibonacciLookupTable();
	unsigned int get_fibo_at(int n); //prints specific fibo, the nth fibo

	//mehr funktionalität
	void calculate_fibo(int index); //kein unsigned int, compiler meckert dann wegen pow()
	void get_fibo_series(); //prints the whole fibo series !!get->print ersetzen oder array zurückgeben


private:
	unsigned int *first_fibo_ptr;
	bool *checker_ptr; //checks if already calculated

};

FibonacciLookupTable::FibonacciLookupTable(unsigned int number_of_elements) {
	first_fibo_ptr = new unsigned int[number_of_elements];
	checker_ptr = new bool[number_of_elements]; //Anderer Ansatz, zweidim array?
	//Wie setze ich hier elegant das Ganze array auf false?
	for (int i=0; i<number_of_elements; ++i) {
		*(checker_ptr + i) = false;
	}
}

FibonacciLookupTable::~FibonacciLookupTable() {
	delete[] first_fibo_ptr;
	first_fibo_ptr = 0;
	delete[] checker_ptr;
	checker_ptr = 0;
}

void FibonacciLookupTable::get_fibo_series() {

}

unsigned int FibonacciLookupTable::get_fibo_at(int n) {
	calculate_fibo(n);
	return  (*(first_fibo_ptr + n));
}

void FibonacciLookupTable::calculate_fibo(int index) {
	if (*(checker_ptr + index) == false) {

	//Uses Moivre-Binet
	*(first_fibo_ptr + index) = std::floor(1.0/std::sqrt(5) *
			(std::pow((0.5*(1+std::sqrt(5))),index) - std::pow((0.5*(1-std::sqrt(5))),index)));

	*(checker_ptr + index) = true;
	std::cout << "\nWert berechnet und abgespeichert.\n";
	} else {
		std::cout << "\nWert bereits berechnet.\n";
	}
	//Optimization: approximation for big numbers

}

int main() {
	FibonacciLookupTable LUT(10);
	unsigned int an_element;
	std::cout << "Das wievielte Element?: ";
	std::cin >> an_element;
	std::cout << LUT.get_fibo_at(an_element);
	std::cout << LUT.get_fibo_at(an_element);

}
