#include <iostream>
using namespace std;

class Base
{
public:
    virtual void fun() {}
};

class Derived : public Base
{
public:
    virtual void fun(double i) {}
};

int main()
{
    Derived t1;
    Base *t2 = new Derived();
}