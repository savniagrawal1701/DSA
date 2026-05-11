#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int revdigit(int n)
{

    int rev= 0;

    while (n > 0)
    {
int a=n%10;
        rev = rev*10 +a ;

        n = n / 10;
    }

    return rev;
}

int main()
{
    int N = 229823;
    cout << "N: " << N << endl;
    int digits = revdigit(N);
    cout << "Number of Digits in N: " << digits << endl;
    return 0;
}
