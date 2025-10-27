// optimised
#include <bits/stdc++.h>
using namespace std;
int slargest(vector<int> &a, int n)
{
    int largest = a[0];
    int secondl = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            
            secondl = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secondl)//when current element is less than largest and greater than second largest
        //when u find that first element is largest and rest all are smaller then first element
        {
            secondl = a[i];
        }
    }

    return secondl;
}
int main()
{
    int n;
    cout << "entre the number of elements" << endl;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
      
    }
    int ans =slargest(a, n);
    cout<<ans;
    return 0;
}