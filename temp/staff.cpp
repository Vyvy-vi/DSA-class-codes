#include <iostream>
using namespace std;

class Staff
{
    string name;

public:
    Staff(string _name = "unknown") : name(_name) {}
    void print1() { cout << name << " "; }
};

class Teacher : protected Staff
{
    string deptName;

public:
    Teacher(string _name, string _deptName) : Staff(_name), deptName(_deptName) {}
    void print2() { cout << deptName << " "; }
};

int main(void)
{
    Teacher t("Partha", "CSE");
    // t.print1();
    t.print2();
}