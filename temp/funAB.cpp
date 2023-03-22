#include <iostream>
using namespace std;

int x = 0;

class A
{
public:
    A() { x += 2; }
    ~A() { x -= 1; }
};

class B : public A
{
public:
    B() { x += 3; }
    ~B() { x -= 2; }
};

void fun()
{
    B t;
    A *t1 = new B();
    cout << x << " ";
    delete t1;
}

int main()
{
    fun();
    cout << x << " ";
}