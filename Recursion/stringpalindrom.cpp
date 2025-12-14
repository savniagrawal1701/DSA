#include<bits/stdc++.h>
using namespace std;

bool palindrome(int i, string& s) {

    if (i >= s.length() / 2) return true;

    if (s[i] != s[s.length() - i - 1]) return false;

    return palindrome(i + 1, s);
}

int main() {
   
    string s = "madam";
    
    cout << palindrome(0, s); 
    cout << endl;
    return 0;
}