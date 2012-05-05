#include <iostream>

using namespace std;

class FibonacciLUT {
public:
	FibonacciLUT(int NumberOfNumbers);
	~FibonacciLUT();
	long GetFibonacciNumber(int n);
private:
	long* FibonacciArray;
	int SizeOfLUT;
	int LargestGeneratedNumber;
	void GenerateNumbers(int ToNumber);
};

FibonacciLUT::FibonacciLUT(int NumberOfNumbers):SizeOfLUT(NumberOfNumbers) {
	if(SizeOfLUT < 1) {
		cout << "zu kleine LUT, daher auf 10 gesetzt." << endl;
		// irgendwie sinnvoll abbrechen, alternativ Startwert setzen.
		SizeOfLUT=10;

	}
	if(SizeOfLUT>95) { // Wert durch Probieren ermittelt
		cout << "LUT zu groß, daher auf 95 gesetzt." << endl;
		SizeOfLUT=95;
	}
	FibonacciArray = new long[SizeOfLUT];

	FibonacciArray[0]=0;
	LargestGeneratedNumber=0;

	if(SizeOfLUT>=2) {
		FibonacciArray[1]=1;
		LargestGeneratedNumber=1;
	}
	//rest per Schleife
	// on demand



}

void FibonacciLUT::GenerateNumbers(int n) {
	for(int i=LargestGeneratedNumber+1; i<=n; i++) {
		FibonacciArray[i] = FibonacciArray[i-1] + FibonacciArray[i-2];
	}
}

FibonacciLUT::~FibonacciLUT() {
	delete[] FibonacciArray;
}

long FibonacciLUT::GetFibonacciNumber(int n) {
	if((n<0)|(n>=SizeOfLUT)) {
		cout << "Out of Range!" << endl;
		return -1;
	} else {
		if(n > LargestGeneratedNumber)
			GenerateNumbers(n);
		return FibonacciArray[n];
	}
}


int main()
{
	int n = 0;
	cout << "Size of LUT? " << flush;
	cin >> n;
	
	FibonacciLUT LUT(n);

	int input=1;
	cout << "-1 zum Beenden." << endl;

	while(input!=-1) {
		cout << "Fibonacci number? " << flush;
		cin >> input;
		cout << LUT.GetFibonacciNumber(input) << endl;
	}
	


	return 0;
}
