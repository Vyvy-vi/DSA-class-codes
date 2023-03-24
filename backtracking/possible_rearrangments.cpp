// WITHOUT BACKTRACKING

#include <iostream>
#include <stack>
using namespace std;

void rearrange(string pattern, int lvl = 0)
{
    if (lvl == pattern.size())
        cout << pattern << endl;

    for (int i = lvl; i < pattern.size(); i++)
    {
        swap(pattern[lvl], pattern[i]);
        rearrange(pattern, lvl + 1);
        swap(pattern[lvl], pattern[i]);
    }
}

int main()
{
    string pattern = "ABC";
    rearrange(pattern);
}
