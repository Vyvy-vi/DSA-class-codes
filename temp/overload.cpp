#include <iostream>
using namespace std;
class intString
{
    int *arr;
    int n;

public:
    intString(int k) : n(k), arr(new int[k])
    {
        cout << "..";
    } // LINE-1
    ~intString()
    {
        cout << "--";
    }
    operator int()
    { // LINE-2
        return arr[--n];
    }
    intString &operator=(int &k)
    { // LINE-3

        int t;
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            this->arr[j] = t;
        }
        return *this;
    }
};
int main()
{
    int k;
    cin >> k;
    intString s(k);
    s = k;
    for (int i = 0; i < k; i++)
        cout << static_cast<int>(s) << " ";
    return 0;
}