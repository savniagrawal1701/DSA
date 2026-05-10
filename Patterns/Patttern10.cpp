#include <bits/stdc++.h>
using namespace std;

void pattern10(int N)
{

    for (int i = 1; i <= 2 * N - 1; i++)
    {

        int stars = i;

        if (i > N)
            stars = 2 * N - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{

    int N = 5;
    pattern10(N);

    return 0;
}