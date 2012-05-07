/*
 * fibonacci-lut.cpp
 *
 *  Created on: 05.05.2012
 *      Author: prime
 * */


#include <iostream>
#include <cmath>

class FibonacciLookupTable {
public:
	FibonacciLookupTable(unsigned int number_of_elements);
	~FibonacciLookupTable();
	unsigned int get_fibo_at(unsigned int n); // returns the fibo with index n
	void calculate_fibo(unsigned int index); //calculates fibo with given index


private:
	unsigned int *first_fibo_ptr; //points to the first element of array on heap
	bool *checker_ptr; //checks if already calculated

};

FibonacciLookupTable::FibonacciLookupTable(unsigned int number_of_elements) {
	first_fibo_ptr = new unsigned int[number_of_elements];
	checker_ptr = new bool[number_of_elements];
	for (unsigned int i=0; i<number_of_elements; ++i) {
		*(checker_ptr + i) = false;
	}
}

FibonacciLookupTable::~FibonacciLookupTable() {
	//Clean up the Heap
	delete[] first_fibo_ptr;
	first_fibo_ptr = 0;
	delete[] checker_ptr;
	checker_ptr = 0;
}

unsigned int FibonacciLookupTable::get_fibo_at(unsigned int n) {
	calculate_fibo(n);
	return  (*(first_fibo_ptr + n-1));
}

void FibonacciLookupTable::calculate_fibo(unsigned int index) {
	if (*(checker_ptr + (index-1)) == false) {
		//Uses Moivre-Binet
		*(first_fibo_ptr + (index-1)) = (1.0/std::sqrt(5.0) * //kein std::floor bei ungenäherter formel
			(std::pow((0.5*(1+std::sqrt(5.0))),(double)(index-1)) - std::pow((0.5*(1-std::sqrt(5.0))),(double)(index-1))));
		*(checker_ptr + (index-1)) = true;
		std::cout << "\nWert berechnet und abgespeichert.\n";
	} else {
		std::cout << "\nWert bereits berechnet.\n";
	}
	//Optimization: approximation for big numbers

}

int main() {
	FibonacciLookupTable LUT(10);
	unsigned int x;
	std::cout << "Das wievielte Element?: ";
	std::cin >> x;
	if (x==0) {
		std::cout << "Fibonacci Zahlen fangen mit dem Index 1 an.";
	} else {
		std::cout << LUT.get_fibo_at(x);
		std::cout << LUT.get_fibo_at(x);
	}
}
