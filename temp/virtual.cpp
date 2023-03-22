#include <iostream>
using namespace std;

class Virtual
{
public:
    virtual void fun() = 0;
};

void Virtual::fun()
{
    cout << "Pure virtual function";
}

int main(void)
{
    p->fun();
}