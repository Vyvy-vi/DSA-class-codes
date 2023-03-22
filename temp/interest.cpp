#include <iostream>
using namespace std;
class Interest
{
protected:
    double i;

public:
    Interest(double _i) : i(_i) {}
    void calculate() { cout << i << endl; }
};

class FDInterest : public Interest
{
public:
    FDInterest(double _i) : Interest(_i) {}
    void calculate(double prin) { cout << i * prin << endl; }
};

int main(void)
{
    FDInterest i1(6.75);
    i1.calculate();
    return 0;
}