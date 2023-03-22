#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun() { cout << "1"; }
};

class B : public A
{
public:
    void fun() { cout << "2"; }
};

class C : public B
{
public:
    void fun() { cout << "3"; }
};

int main()
{
    C *nb = new C;
    nb->B::fun();
}