// WITHOUT BACKTRACKING

#include <iostream>
#include <stack>
using namespace std;

void rearrange(string pattern, string antipattern = "", int lvl = 0)
{

    if (lvl == pattern.size() && pattern.find(antipattern) == string::npos)
        cout << pattern << " ";

    for (int i = lvl; i < pattern.size(); i++)
    {
        swap(pattern[lvl], pattern[i]);
        rearrange(pattern, antipattern, lvl + 1);
        swap(pattern[lvl], pattern[i]);
    }
}

int main()
{
    string pattern = "ABC";
    string antipattern = "AB";
    rearrange(pattern, antipattern);
}
