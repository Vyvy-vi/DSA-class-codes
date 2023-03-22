#include <iostream>
using namespace std;

class B
{
protected:
    int X;

public:
    B(int i = 0) : X(i) {}
};

class D : public B
{
    B b;

public:
    D(B b1, int i = 0) : B(i), b(b1) {}
    void print1() { cout << X << endl; }
    // void print2() { cout << b.X << endl; }
};

int main(void)
{
    B b(5);
    D d(b, 10);

    d.print1();
    // d.print2();
}