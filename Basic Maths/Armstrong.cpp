#include <bits/stdc++.h>
using namespace std;


class ArmstrongChecker {
public:
    
    static bool isArmstrong(int num) {
        int k = to_string(num).length(); 
        int sum = 0;
        int n = num;

        while (n > 0) {
            int ld = n % 10;            
            sum += pow(ld, k);          
            n /= 10;                    
        }

        return sum == num; 
    }
};

int main() {
    int number = 153;

    
    if (ArmstrongChecker::isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}