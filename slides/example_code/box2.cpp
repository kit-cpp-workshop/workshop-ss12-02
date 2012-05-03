#include <iostream>
using namespace std;

class Box {
public:
    void Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    };
    void ~Box() {
        cout << "box is being deleted";
    };
    double getVolume() {
        return length * width * height;
    };
private:
    double length;
    double width;
    double height;
};

int main() {
    Box myBox(3, 5, 2.7);
    cout << myBox.getVolume();
}