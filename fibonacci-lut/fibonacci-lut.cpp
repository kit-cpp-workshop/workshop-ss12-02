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
	unsigned int get_fibo_at(unsigned int n); // Returns the Fibonacci with index n, starting with index of 1
	void calculate_fibo(unsigned int index); // Calculates the Fibonacci with the given index, note: also starting with index of 1

private:
	unsigned int *first_fibo_ptr; //points to the first element of array on heap
};

FibonacciLookupTable::FibonacciLookupTable(unsigned int number_of_elements) {
	// Puts the LUT (Array) on the Heap
	first_fibo_ptr = new unsigned int[number_of_elements];
	for (unsigned int i=0; i<number_of_elements; ++i) {
		first_fibo_ptr[i] = 0;
	}
}

FibonacciLookupTable::~FibonacciLookupTable() {
	//Clean up the Heap
	delete[] first_fibo_ptr;
	first_fibo_ptr = 0;
}

unsigned int FibonacciLookupTable::get_fibo_at(unsigned int n) {
	calculate_fibo(n);
	return  (first_fibo_ptr[n-1]);
}

void FibonacciLookupTable::calculate_fibo(unsigned int index) { //Fibonacci starts with Index of 1
	if (first_fibo_ptr[index-1] == 0) {
		//Uses Moivre-Binet
		first_fibo_ptr[index-1] = (1.0/std::sqrt(5.0) * //kein std::floor bei ungenäherter formel
			(std::pow((0.5*(1+std::sqrt(5.0))),(double)(index-1)) - std::pow((0.5*(1-std::sqrt(5.0))),(double)(index-1))));
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
	} else if (x>10) {
		std::cout << "Nicht in der LUT vorhanden.";
	} else {
		std::cout << LUT.get_fibo_at(x);
		std::cout << LUT.get_fibo_at(x);
	}
}
