#include <iostream>
using namespace std;

class C
{
public:
    void print() { cout << "C Programming" << endl; }
};

class CPP : public C
{
public:
    void print() { cout << "C++ Programming" << endl; }
};

int main(void)
{
    C *a1 = new C();
    C *b1 = new CPP();

    a1->print();
    b1->print();

    return 0;
}