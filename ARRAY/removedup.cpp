// optimised
#include <bits/stdc++.h>
using namespace std;
int rdup(vector<int> &a, int n)
{
    
  int i=0;
  for(int j=1;j<n;j++)  {
    if (a[j]!=a[i]){
        a[i+1]=a[j];
        i++;
    }
  }
  return i+1;
}
int main()
{
    int n;
    cout << "entre the number of elements" << endl;
    cin >> n;
cout<<"entre the elements in sorted order"<<endl;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
      
    }
    cout<<"ans is "<<endl;
    int ans =rdup(a, n);
    cout<<ans;
    return 0;
}