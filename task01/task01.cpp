#include <iostream>

using namespace std;

class FibonacciLUT {
public:
	FibonacciLUT(int NumberOfNumbers);
	~FibonacciLUT();
	int GetFibonacciNumber(int n);
private:
	int* FibonacciArray;
	int SizeOfLUT;
	int LargestGeneratedNumber;
	void GenerateNumbers(int ToNumber);
};

FibonacciLUT::FibonacciLUT(int NumberOfNumbers):SizeOfLUT(NumberOfNumbers) {
	if(SizeOfLUT < 1) {
		cout << "zu kleine LUT" << endl;
		// irgendwie sinnvoll abbrechen.

	}
	FibonacciArray = new int[SizeOfLUT];

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

int FibonacciLUT::GetFibonacciNumber(int n) {
	if((n<0)|(n>SizeOfLUT)) {
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

	while(input!=0) {
		cout << "Fibonacci number? " << flush;
		cin >> input;
		cout << LUT.GetFibonacciNumber(input) << endl;
	}
	


	return 0;
}
