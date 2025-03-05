#include "iostream"
using namespace std;

class base{
public:
    int i, b;
    void setData(int i, int b){
        this->i = i;
        this->b = b;
    }
};

class derived1 : public base{
public:
    int x, y;
    void setXY(int x, int y){
        this->x = x;
        this->y = y;
        }
    void showData1(){
        cout << "This is the data of Base class set by derived class 1" << endl;
        cout << "i = " << i << endl << "b = " << b << endl;
    }
};

class derived2 : public base{
public:
    int u, v;
    void setUV(int u, int v){
        this->u = u;
        this->v = v;
    }
    void showData2(){
        cout << "This is the data of Base class set by derived class 2" << endl;
        cout << "i = " << i << endl << "b = " << b << endl;
    }
};

class derived3 : public base, public derived1, public derived2{
public:
    void showData3(){
        cout << "This is the data of derived class 1 set by derived class 3" << endl;
        cout << "x = " << x << endl << "y = " << y << endl;
        cout << "This is the data of derived class 2 set by derived class 3" << endl;
        cout << "u = " << u << endl << "v = " << v << endl;
    }
};

int main(){
    derived1 d1;
    derived2 d2;
    derived3 d3;
    d1.setData(4,5);
    d1.showData1();
    d2.setData(6,7);
    d2.showData2();
    d3.setXY(10, 11);
    d3.setUV(12, 13);
    d3.showData3();
    return 0;
}
