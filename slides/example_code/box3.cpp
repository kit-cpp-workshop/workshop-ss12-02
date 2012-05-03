#include <iostream>
using namespace std;

class Box {
public:
    Box(double l, double w, double h);
    ~Box();
    double getVolume();
private:
    double length;
    double width;
    double height;
};

double Box::getVolume() {
    return length * width * height;
}

Box::Box(double l, double w, double h) : width(w), length(l), height(h) {
    cout << "Box is being created";
}

Box::~Box()
{
    cout << "Box is being destroyed";
}

int main() {
    Box* myBox = new Box(3, 5, 2.7);
    cout << myBox->getVolume();
    cout << myBox->length; // Fehler!
    delete myBox;
}