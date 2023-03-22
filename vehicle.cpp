#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void run() = 0;
    virtual void stop() = 0;
};

class Car : public Vehicle
{
public:
    void run();
    void stop();
};

class Truck : public Car
{
public:
    void run();
    void stop();
};

int main()
{
    cout << "Hello World!" << endl;
}