#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> marks;
    marks.insert({3, 65});
    marks.insert({1, 85});
    marks.insert({7, 95});
    marks.insert({12, 5});

    for (auto x : marks)
    {
        cout << x.first << ": " << x.second << endl;
    }
}