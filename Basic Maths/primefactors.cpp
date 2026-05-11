#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;

            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 1483;
    bool isPrime = checkPrime(n);

    if (isPrime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}