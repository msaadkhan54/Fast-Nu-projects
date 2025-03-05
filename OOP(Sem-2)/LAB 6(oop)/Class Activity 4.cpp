#include <iostream>
using namespace std;

class base {
public:
    int i, b;
    base(int i, int b) {
        this->i = i;
        this->b = b;
    }
};

class derived1 : public base {
public:
    derived1(int i, int b) : base(i, b) {}
    void showData1() {
        cout << "This is the data of Base class set by derived class 1" << endl;
        cout << "i = " << i << endl << "b = " << b << endl;
    }
};

class derived2 : public base {
public:
    derived2(int i, int b) : base(i, b) {}
    void showData2() {
        cout << "This is the data of Base class set by derived class 2" << endl;
    	cout << "i = " << i << endl << "b = " << b << endl;
	}
};

class derived3 : public base {
public:
    derived3(int i, int b) : base(i, b) {}
    void showData3() {
        cout << "This is the data of Base class set by derived class 3" << endl;
        cout << "i = " << i << endl << "b = " << b << endl;
    }
};

int main() {
    derived1 d1(4, 5);
    derived2 d2(6, 7);
    derived3 d3(8, 9);
    d1.showData1();
    d2.showData2();
    d3.showData3();
    return 0;
}
