#include <iostream>

using namespace std;

class fibonacciLUT {

public:
    fibonacciLUT(unsigned int number_N);
    ~fibonacciLUT();
    unsigned int get(unsigned int pos);
    
private:
    unsigned int* fibonacci;
};

fibonacciLUT::~fibonacciLUT() {
    delete[] fibonacci;
}

fibonacciLUT::fibonacciLUT(unsigned int number_N) {
    
    unsigned int current = 1;
    unsigned int old = 0;
    
    fibonacci = new unsigned int[number_N];
    for(unsigned int i = 0; i < number_N; i++) {
        
        // new Fibonacci number:
        unsigned int temp = current;
        current += old;
        old = temp;
        fibonacci[i] = current;
    }

}

unsigned int fibonacciLUT::get(unsigned int pos) {
    return fibonacci[pos];
}


int main()
{
    // Heap: fibonacciLUT* zahlen = new fibonacciLUT(100);
    fibonacciLUT zahlen(100);
    
    unsigned int a;
    cout << "Die wievielte Fibonacci-Zahl?" << endl;
    cin >> a;
    
    // Heap: cout << zahlen->get(a) << endl;   
    cout << zahlen.get(a) << endl;
    
    // Heap: delete zahlen;
	
	return 0;
}
