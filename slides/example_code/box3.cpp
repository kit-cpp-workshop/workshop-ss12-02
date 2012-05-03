#include <iostream>
using namespace std;

class Box {
public:
    void Box(double l, double w, double h);
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

int main() {
    Box* myBox = new Box(3, 5, 2.7);
    cout << myBox->getVolume();
    cout << myBox->length; // Fehler!
}