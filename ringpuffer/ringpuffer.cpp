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
	for (unsigned int i = 0; i <= size; ++i) {
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
		return true; //worked
	} else {
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


int main() {
	std::cout << "##";
	Ringpuffer puffer(5);
	std::cout << "##";
	double temp;
	std::cout << "##";
	for (unsigned int i=0; i<6; ++i) {
		std::cout << "double speichern:";
		std::cin >> temp;
		puffer.push(temp);
	}

	puffer.pop();
	puffer.pop();

	for (unsigned int i=0; i<6; ++i) {
		std::cout << "double speichern:";
		std::cin >> temp;
		puffer.push(temp);
	}


	return 0;
}


