#include <iostream>

using namespace std;

class Ring
{
public:
	Ring(int n);
	~Ring();
	double pop();
	bool push(double d);
private:
	int nextIndex;
	int size;
	double* lut;
	int beginning;
	bool empty;
};

Ring::Ring(int n) {
	nextIndex = 0;
	beginning = 0;
	lut = new double[n];
	size = n;
	empty = true;
}

Ring::~Ring() {
	delete[] lut;
	lut = 0;
}

double Ring::pop() {
	if (nextIndex == beginning && empty) {
		return 0;
	} else {
		empty = true;
		double r = lut[beginning];
		beginning++;
		if (beginning == size) {
			beginning = 0;
		}
		return r;
	}
}

bool Ring::push(double d) {
	if (nextIndex == beginning && !empty) {
		return false;
	} else {
		empty = false;
		lut[nextIndex] = d;
		nextIndex++;
		if (nextIndex == size) {
			nextIndex = 0;
		}
		return true;
	}
}

int main()
{
	int n = 0;
	cout << "How many numbers? " << flush;
	cin >> n;

	Ring fib = Ring(n);

	cout << fib.pop() << "\n";
	cout << fib.push(1.234) << "\n";
	cout << fib.push(6.234) << "\n";
	cout << fib.push(6.234) << "\n";
	cout << fib.push(6.234) << "\n";
	cout << fib.push(6.234) << "\n";
	cout << fib.push(6.234) << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";
	cout << fib.pop() << "\n";

	return 0;
}
