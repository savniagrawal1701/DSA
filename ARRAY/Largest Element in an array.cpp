
//optimised solution
#include <iostream>
using namespace std;
void largestn(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];
       
    }
     cout << largest;
}
    int main()
    {
int n;
cout<<"entre the number of elements in an array"<<endl;
cin>>n;

int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
largestn(arr,n);
        return 0;
    }
