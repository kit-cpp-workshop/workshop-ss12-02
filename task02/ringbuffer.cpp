#include <iostream>
#include <iomanip>
#include "ringbuffer.h"

using namespace std;

ringbuffer::ringbuffer(size_t init) {
    // Initialize new buffer with size (size):
    size = init;
    buffer = new double[size];
    
    // Set pointer to initial position:
    in = buffer;
    out = buffer;
    filled = 0;
}

ringbuffer::~ringbuffer() {
    delete[] buffer;
}

bool ringbuffer::push(double data) {
    if(filled != size) {
        // Writing "data" to pos "in":
        *in = data;
        filled++;
        if(in < buffer+size-1) in++;
        else in = buffer;
        return true;
    }
    else {
        // Buffer is full, read old elements out:
        return false;
    }
}

size_t ringbuffer::filling_level() {
    return filled;
}

double ringbuffer::pop() {
    if(filled > 0) {
        double temp = *out;
        filled--;
        if(out < buffer + size - 1) out++;
        else out = buffer;
        return temp;
    }
    else return 0;
}

double ringbuffer::get(size_t pos) {
    return buffer[pos];
}

void ringbuffer::debug_print() {

    cout << "|";
    for(int i = 0; i < size; i++) {
        cout << setw(6) << buffer[i] << "|";
    }
    cout << endl;
}

int main()
{
    ringbuffer* puffer = new ringbuffer(3);
    double a;
    
    for(int i = 0; i < 15; i++ ) {
        cin >> a;
        if(!puffer->push(a)) cout << "buffer full. call pop()" << endl;
        if(i%2==0) cout << "pop: " << puffer->pop() << endl;
        puffer->debug_print();
    }
    
    puffer->debug_print();
    
    delete puffer;
	
	return 0;
}
