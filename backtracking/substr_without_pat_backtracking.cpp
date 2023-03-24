// WITH BACKTRACKING

#include <iostream>
#include <stack>
using namespace std;

bool isSafe(string pattern, int lvl, int curr)
{
    // if (str[l - 1] == 'A' && str[i] == 'B')
    // {
    //     return false;
    // }
    // if (str[i] == 'A' && str[l] == 'B')
    //     return false;
    // return true;

    return !(pattern[lvl - 1] == 'A' && pattern[curr] == 'B');
}

void rearrange(string pattern, int lvl = 0)
{

    if (lvl == pattern.size())
        cout << pattern << " ";

    for (int i = lvl; i < pattern.size(); i++)
    {
        if (isSafe(pattern, lvl, i))
        {
            swap(pattern[lvl], pattern[i]);
            rearrange(pattern, lvl + 1);
            swap(pattern[lvl], pattern[i]);
        }
    }
}

int main()
{
    string pattern = "ABC";
    rearrange(pattern);
}
