/*
 * ringpuffer.cpp
 *
 *  Created on: 09.05.2012
 *      Author: prime
 */

#include <iostream>

class Ringpuffer {
public:
	Ringpuffer(unsigned int number_of_elements);
	~Ringpuffer();
	bool push(double date); //add new date, return if it worked, checker=false, error if old element still in puffer
	double pop(); //get date, checker = true
	void print_puffer(); //printed alle daten im Puffer, beginnend mit ältesten element (fifo)
	//TODO: Array als Rückgabewert
private:
	double *first_memory; //points to the first empty element in array
	bool *first_check;
	unsigned int input;
	unsigned int output;
	unsigned int size;
};

Ringpuffer::Ringpuffer(unsigned int number_of_elements) {
	input = 0; //location of last input
	output = 0; //location of last output
	size = number_of_elements;

	first_memory = new double[number_of_elements];
	first_check = new bool[number_of_elements];
	for (unsigned int i=0; i<size; ++i) {
		first_memory[i] = 0;
		first_check[i] = true;
	}
}

Ringpuffer::~Ringpuffer() {
	//clean heap
	delete[] first_memory;
	first_memory = 0;
}

bool Ringpuffer::push(double date) {
	if (first_check[input] == true) {
		first_memory[input] = date;
		first_check[input] = false;
		++input;
		if (input == size) {
			input = 0;
		}
		std::cout << "##gespeichert";
		return true; //worked
	} else {
		std::cout << "voll";
		return false; //puffer full or other things happened
	}
}

double Ringpuffer::pop() {
	first_check[output] = true;
	double temp = first_memory[output];
	++output;
	if (output == size) {
		output = 0;
	}
	return temp;
}

void Ringpuffer::print_puffer() {
	for (unsigned int i=0; i<size; ++i) {
		std::cout << first_memory[input+i] << " - ";
	}
}

//Nur Testcode ab hier...
int main() {
	Ringpuffer puffer(5);
	double temp;

	for (unsigned int i=0; i<6; ++i) {
		std::cout << "##double speichern:";
		std::cin >> temp;
		puffer.push(temp);
	}

	puffer.print_puffer();

	puffer.pop();
	puffer.pop();

	for (unsigned int i=0; i<6; ++i) {
		std::cout << "##double speichern:";
		std::cin >> temp;
		puffer.push(temp);
	}

	puffer.print_puffer();

}


