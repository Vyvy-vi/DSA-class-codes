#include <iostream>
#include <queue>
using namespace std;

struct node
{
    char ch;
    int freq;

    node(int _freq, char _ch = '$') : freq(_freq), ch(_ch) {}
};

int main()
{
    priority_queue<node *, greater<node *>> minHeap;

    string characters = "adbef";
    int freq[] = {10, 50, 20, 40, 80};

    for (int i = 0; i < characters.size(); i++)
    {
        minHeap.push(new node(freq[i], characters[i]));
    }
}
