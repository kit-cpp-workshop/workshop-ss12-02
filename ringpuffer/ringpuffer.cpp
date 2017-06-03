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
	double *first_memory_ptr; //points to the first empty element in array
	bool *first_check_ptr;
	unsigned int input;
	unsigned int output;
	unsigned int size;
};

Ringpuffer::Ringpuffer(unsigned int number_of_elements) {
	input = 0; //location of last input
	output = 0; //location of last output
	size = number_of_elements;

	first_memory_ptr = new double[number_of_elements];
	first_check_ptr = new bool[number_of_elements];
	for (unsigned int i=0; i<size; ++i) {
		first_memory_ptr[i] = 0;
		first_check_ptr[i] = true;
	}
}

//Gibt es hier wieder was besseres wie 2 arrays?
Ringpuffer::~Ringpuffer() {
	//clean heap
	delete[] first_memory_ptr;
	first_memory_ptr = 0;
	delete[] first_check_ptr;
	first_check_ptr = 0;
}

bool Ringpuffer::push(double date) {
	if (first_check_ptr[input] == true) {
		first_memory_ptr[input] = date;
		first_check_ptr[input] = false;
		++input;
		if (input == size) {
			input = 0;
		}
		std::cout << "Wert gespeichert" << std::endl;
		return true; //worked
	} else {
		std::cout << "Puffer voll" << std::endl;
		return false; //puffer full or other things happened
	}
}

double Ringpuffer::pop() {
	first_check_ptr[output] = true;
	double temp = first_memory_ptr[output];
	++output;
	if (output == size) {
		output = 0;
	}
	std::cout << temp << std::endl;
	return temp;
}

//haha, muss selber bisschen lachen darüber. Hab aber kein Kopf mir grad mehr Gedanken zu machen
void Ringpuffer::print_puffer() {
	unsigned int elements_printed = 0;
	for (unsigned int i=0; output+i<size; ++i) {
		std::cout << std::endl << first_memory_ptr[output+i];
		++elements_printed;
	}
	for (unsigned int i=0; i<size-1-output; ++i) {
		if (elements_printed == size)
			break;
		std::cout << std::endl << first_memory_ptr[i];
		++elements_printed;
	}
	std::cout << std::endl;
}

//Nur Testcode ab hier...
int main() {
	Ringpuffer puffer(3);
	std::cout << "Zahlen von 0 bis 4 Versuchen einzuspeichern. Kein Platz fuer die 4 im Puffer" <<std::endl;
	for (unsigned int i=0; i<4; ++i) {
		puffer.push(i);
	}
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Pufferinhalt ausgeben" << std::endl;
	puffer.print_puffer();
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Erstes eingebenes Element anzeigen" << std::endl;
	puffer.pop();
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Zahlen von 4 bis 6 Versuchen einzuspeichern. Kein Platz für 5,6 im Puffer" << std::endl;
	for (unsigned int i=4; i<7; ++i) {
		puffer.push(i);
	}
	std::cout << "----------------------------------------" << std::endl;

	std::cout << "Pufferinhalt ausgeben" << std::endl;
	puffer.print_puffer();
	std::cout << "----------------------------------------" << std::endl;

}


