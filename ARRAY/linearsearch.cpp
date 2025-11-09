#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int linearSearch(vector<int> &v, int size, int target)
    {
        for (int i = 0; i < size; ++i)
        {
            if (v[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    solution s1;
    vector<int> v = {7, 5, 4, 3, 9, 1, 0};
    int s = v.size();
    int ans = s1.linearSearch(v, s, 0);
    cout << "The index at which target is found :" << ans;
}