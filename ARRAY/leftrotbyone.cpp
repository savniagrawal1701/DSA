#include<iostream>
using namespace std;
void leftro(int a[],int n){
   int temp=a[0];
   for(int i=1;i<n;i++){
    a[i-1]=a[i];
   }
   a[n-1]=temp;

}
int main()
{
    int n;
    cout << "entre the number of elements" << endl;
    cin >> n;
cout<<"entre the elements in sorted order"<<endl;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
      
    }
    cout<<"ans is "<<endl;
    leftro(a, n);
     for (int i = 0; i < n; i++)
    {
       cout<<a[i];
      
    }
    return 0;
}