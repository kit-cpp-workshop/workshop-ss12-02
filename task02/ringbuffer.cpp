#include <iostream>
#include "ringbuffer.h"

using namespace std;

ringbuffer::ringbuffer(size_t init) {
    // Initialize new buffer with size (size):
    size = init;
    buffer = new double[size];
    
    // Set pointer to initial position:
    in = 0;
    out = size - 1;
}

ringbuffer::~ringbuffer() {
    delete[] buffer;
}

bool ringbuffer::push(double data) {
    if(in != out) {
        // Writing "data" to pos "in":
        buffer[in] = data;
        if(in < size - 1) in++;
        else in = 0;
        return true;
    }
    else {
        // Buffer is full, read old elements out:
        return false;
    }
}


double ringbuffer::pop() {
    double temp = buffer[out];
    if(out < size - 1) out++;
    else out = 0;
    return temp;
}

double ringbuffer::get(size_t pos) {
    return buffer[pos];
}

int main()
{
    ringbuffer* puffer = new ringbuffer(5);
    double a;
    
    for(int i = 0; i < 15; i++ ) {
        cin >> a;
        if(!puffer->push(a)) cout << "buffer full. call pop()" << endl;
        if(i%2==0) cout << "pop: " << puffer->pop() << endl;
    }
    
  for(int i = 0; i < 5; i++) {
    cout << "pos" << i << " : " << puffer->get(i) << endl;
  }
	
	return 0;
}
