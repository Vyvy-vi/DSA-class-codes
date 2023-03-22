#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A "; }
    ~A() { cout << "~A "; }
};

class B : public A
{
public:
    B() { cout << "B "; }
    ~B() { cout << "~B "; }
};

class C : public B
{
public:
    C() { cout << "C "; }
    ~C() { cout << "~C "; }
};

int main(void)
{
    bool arr[5] = {false};
    A *t1 = new C;
    delete t1;
}