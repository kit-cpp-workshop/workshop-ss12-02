/*
 * task01.cpp
 *
 *  Created on: 04.05.2012
 *      Author: Steven Weitemeyer & Holger Drees
 */
#include<iostream>

using namespace std;



class FibonacciLUT {

public:
	FibonacciLUT(long n);
	~FibonacciLUT();
	long get(long n);

private:
	long* LUT;
};

FibonacciLUT::FibonacciLUT(long n){
	LUT = new long[n];

	if(n>0) LUT[0]=0;
	if(n>1) LUT[1]=1;

	for(int i=2; i<n; i++){
		LUT[i] = LUT[i-1] + LUT[i-2];
	}
}

FibonacciLUT::~FibonacciLUT(){
	delete[] LUT;
}

long FibonacciLUT::get(long n){
	return LUT[n-1];
}

int main() {
	long anzahl;
	cout << "Feldgroeße angeben";
	cin >> anzahl;
	FibonacciLUT test(anzahl);

	long elementnummer;
	cout << "Elementnummer angeben";
	cin >> elementnummer;
	cout << test.get(elementnummer);

}


