#include <iostream>
using namespace std;

class Base
{
public:
    void fun1() { cout << "1"; }
    virtual void fun2() { cout << "3"; }
};

class Derived : public Base
{
public:
    virtual void fun1() { cout << "2"; }
    void fun2() { cout << "4"; }
};

int main(void)
{

    Base *t = new Derived();
    t->fun1();
    t->fun2();
}