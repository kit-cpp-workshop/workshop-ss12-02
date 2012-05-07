#include <iostream>

using namespace std;


class ringbuffer {

public:
    // Constructor:
    ringbuffer(size_t init);
    ~ringbuffer();
    // Get a value from desired pos:
    double get(size_t pos);
    // Push a new value into the ring buffer:
    bool push(double data);
    // Get the oldest unread value:
    double pop();
    
    // Print out the whole buffer: (debug)
    void debug_print();
    
    size_t filling_level();
     
private:
    double* buffer;
    double* in;
    double* out;
    size_t size;
    size_t filled;
};
