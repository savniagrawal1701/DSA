  #include <bits/stdc++.h> 
   using namespace std; 
void swap_xor(int &a, int &b) {
    if (a == b) {
        return; 
    }
    a = a^b;
    b = a^b;
    a = a^b;
}

int main() {
 

    int x = 10, y = 20;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap_xor(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
