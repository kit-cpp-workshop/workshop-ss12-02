#include <iostream>
#include <vector>

using namespace std;

class fibonacciLUT {

public:
    fibonacciLUT(unsigned int N);
    ~fibonacciLUT();
    unsigned int get(unsigned int pos);
    
private:
    vector< unsigned int > fibonacci;
};


fibonacciLUT::fibonacciLUT(unsigned int N) {
    
    unsigned int current = 1;
    unsigned int old = 0;
    
    for(unsigned int i = 0; i < N; i++) {
        
        // new Fibonacci number:
        unsigned int temp = current;
        current += old;
        old = temp;
        fibonacci.push_back(current);
    }

}

unsigned int fibonacciLUT::get(unsigned int pos) {
    return fibonacci[pos];
}


int main()
{
    fibonacciLUT* zahlen = new fibonacciLUT(100);
    
    unsigned int a;
    cout << "Die wievielte Fibonacci-Zahl?" << endl;
    cin >> a;
       
    cout << zahlen->get(a) << endl;
	
	return 0;
}
