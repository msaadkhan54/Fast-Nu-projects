#include <iostream>
using namespace std;
class A {
public:
    void show() {
        cout << "Base class" << endl;
    }
};
class B : public A {
public:
    void show() {
        cout << "Derived Class" << endl;
    }
};
int main() {
    A *a;
    B b;
    a = &b;
    a->show();
}

