#include <iostream>

using namespace std;

class FibLUT
{
public:
	FibLUT(int n);
	~FibLUT();
	int getFib(int n);
private:
	int nextIndex;
	int* lut;
	int fib(int n);
};

FibLUT::FibLUT(int n) {
	nextIndex = 0;
	lut = new int[n];
}

FibLUT::~FibLUT() {
	delete[] lut;
	lut = 0;
}

int FibLUT::getFib(int n) {
	if(n >= nextIndex) {
		for (int i = nextIndex; i <= n; i++) {
			lut[i] = fib(i);
		}
	}
	return lut[n];
}

int FibLUT::fib(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return lut[n-1] + lut[n-2];
	}
}

int main()
{
	int n = 0;
	cout << "How many numbers? " << flush;
	cin >> n;

	FibLUT fib = FibLUT(n);

	for (int i = 0; i < n; i++) {
		cout << fib.getFib(i) << "\n";
	}

	return 0;
}
