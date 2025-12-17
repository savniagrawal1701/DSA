#include <bits/stdc++.h>
using namespace std;
int converttodecimal(string x)
{
    int len=x.length();
    int power2=1;
    int num=0;
    for(int i =len-1;i>=0;i--){
        if(x[i]=='1'){
            num=num+power2;
          
        }
          power2=power2*2;
    }
    return num;
}
int main(){
    string n ;
    cout<<"Entre the binary no "<<endl;
    cin>>n;
    
    cout<<"The decimal of the given binary no is "<<converttodecimal(n);
    return 0;

}
