#include <iostream>
using namespace std;

// Since its a box, i used area as an example.
class Box {
    int* area;
public:
    Box(int a = 0) {
        area = new int;
        *area = a;
    }
    ~Box() {
        delete area;
    }
    Box(const Box& other) {
        area = new int;
        *area = *other.area;
    }
    Box& operator=(const Box& other) {
        if (this != &other) {
            delete area;
            area = new int;
            *area = *other.area;
        }
        return *this;
    }
    void setArea(int a) {
        *area = a;
    }
    int getArea() const {
        return *area;
    }
};

int main() {

    // Yeh deep copy hai, because yahan pai = operator use ho raha hai, which copies the VALUE instead of the pointer.
    Box b1(10);
    Box b2 = b1; 
    b2.setArea(20);

    cout << "b1 area: " << b1.getArea() << endl;
    cout << "b2 area: " << b2.getArea() << endl;

    // Yeh shallow copy hai, because b3 aur b4 ek hee pointer hai, aur ek hee value ki taraf point kar rahay hain. Agar b3 mai change ayega, toh wohi change b4 mai hoga (and vice versa)
    Box* b3 = new Box(30);
    Box* b4 = b3; 
    b4->setArea(40);

    cout << "b3 area: " << b3->getArea() << endl;
    cout << "b4 area: " << b4->getArea() << endl;

    delete b3; // This makes b4 a dangling pointer.
    return 0;
}