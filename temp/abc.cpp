#include <iostream>
using namespace std;

class A
{
public:
    A(int i) { cout << "A::" << i << " "; }
    ~A() { cout << "~A"; }
};

class B : public A
{
public:
    B(int i) : A(i) { cout << "B::" << i << " "; }
    ~B() { cout << "~B"; }
};

class C : public B
{
public:
    C(int i) : B(i) { cout << "C::" << i << " "; }
    ~C() { cout << "~C"; }
};

C *dp;

void caller()
{
    dp = new C(1);
}

int main(void)
{
    C d(2);
    {
        C d(3);
    }
    caller();
    delete dp;
}