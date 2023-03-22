#include <iostream>
using namespace std;

class Base
{
public:
    void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base
{
public:
    void f() { cout << "Derived::f()" << endl; }
};

int main(void)
{
    Derived obj;
    obj.Base::f();
}