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
     
private:
    double* buffer;
    size_t in;
    size_t out;
    size_t size;
};
