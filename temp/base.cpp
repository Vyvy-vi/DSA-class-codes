#include <iostream>
using namespace std;

class Base
{
public:
    void print() { cout << "Base" << endl; }
};

class Derived : protected Base
{
public:
    Derived() { (new Base)->print(); }
};

int main(void)
{
    Derived t1;
}