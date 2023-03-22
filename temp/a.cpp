#include <iostream>
using namespace std;

class A1
{
protected:
    int t1;

public:
    A1(int _t1) : t1(_t1) {}
};

class A2 : public A1
{
protected:
    int t2;

public:
    A2(int _t1, int _t2) : A1(_t1), t2(_t2) {}
};

class A3 : private A2
{
public:
    A3(int _t1, int _t2) : A2(_t1, _t2) {}
    void print() { cout << t1 << " " << t2; }
};

int main(void)
{
    A3 d(10, 20);
    d.print();
}