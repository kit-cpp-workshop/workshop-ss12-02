/*
 * fibonacci-lut.cpp
 *
 *  Created on: 05.05.2012
 *      Author: prime
 *
 *      Fragen in den Kommentaren
 */


#include <iostream>
#include <cmath>

class FibonacciLookupTable {
public:
	FibonacciLookupTable(unsigned int number_of_elements);
	~FibonacciLookupTable();
	unsigned int get_fibo_at(int n); // returns the fibo with index n
	void calculate_fibo(int index); //kein unsigned int, compiler meckert dann wegen pow()
									   //was tun auser auf unsigned int verzichten?


private:
	unsigned int *first_fibo_ptr;
	bool *checker_ptr; //checks if already calculated

};

FibonacciLookupTable::FibonacciLookupTable(unsigned int number_of_elements) {
	first_fibo_ptr = new unsigned int[number_of_elements];
	checker_ptr = new bool[number_of_elements]; //Besserer Ansatz, zweidim array?
	//Wie setze ich hier elegant das Ganze array auf false?
	//bool[number_of_elements] = {false} will er hier nicht
	for (unsigned int i=0; i<number_of_elements; ++i) {
		*(checker_ptr + i) = false;
	}
}

FibonacciLookupTable::~FibonacciLookupTable() {
	delete[] first_fibo_ptr;
	first_fibo_ptr = 0;
	delete[] checker_ptr;
	checker_ptr = 0;
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
	unsigned int x;
	std::cout << "Das wievielte Element?: ";
	std::cin >> x;
	std::cout << LUT.get_fibo_at(x);
	std::cout << LUT.get_fibo_at(x);

}
