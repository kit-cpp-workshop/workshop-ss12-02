/*
 * fibonacci-lut.cpp
 *
 *  Created on: 05.05.2012
 *      Author: prime
 */


#include <iostream>
#include <vector>

class LUT {
public:
	LUT(unsigned int noe); //noe: number_of_elements
	~LUT();
	void get_fibo_series(); //prints the whole fibo series
	unsigned int get_fibo_at(int n); //prints specific fibo, the nth fibo


private:
	std::vector<unsigned int> fibonacci;
};

LUT::LUT(unsigned int noe) {
	fibonacci.push_back(0);
	fibonacci.push_back(1);

	for (unsigned int i=2; 2<noe; ++i) {
		static unsigned int n_minus = 0;
		static unsigned int n = 1;
		static unsigned int n_plus;
		n_plus = n_minus + n;
		fibonacci.push_back(n_plus);
		n_minus = n;
		n = n_plus;
	}
}

LUT::~LUT() {
	std::cout << "bye lut";
}

void LUT::get_fibo_series() {
	for (unsigned int i=0; i<fibonacci.size(); ++i) {
		std::cout << fibonacci.at(i) << " ";
	}
	std::cout << std::endl;
}

unsigned int LUT::get_fibo_at(int n) {
	return fibonacci.at(n);
}



int main() {
	std::cout << "bla";
	LUT bla(3);

	//LUT *blubb = new LUT(3);
	std::cout << "blubb";
	//std::cout << blubb->get_fibo_at(3);

}
