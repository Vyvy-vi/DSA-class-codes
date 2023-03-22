#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(40);

    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // set uses BST under the hood
    // and thus, the output is in-order traversal of the tree

    s.insert(20);

    auto it = s.find(20);
    if (it == s.end())
        cout << "not present" << endl;
    else
        cout << "present" << endl;

    if (s.count(33) == 1)
        cout << "present" << endl;
    else
        cout << "not present" << endl;

    cout << "Size: " << s.size() << endl;
    s.find(20);
    s.erase(it);
    cout << "Size: " << s.size() << endl;

    set<int, greater<int>> s1; // Decreasing order
    s1.insert(10);
    s1.insert(5);
    s1.insert(20);

    for (auto x : s1)
    {
        cout << x << " ";
    }
    cout << endl;
}