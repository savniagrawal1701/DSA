

#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string str)
{
    if (str.length() <= 1)
        return str;

    string LPS = "";

    for (int i = 1; i < str.length(); i++)
    {

        int low = i;
        int high = i;

        while (str[low] == str[high])
        {
            low--;
            high++;

            if (low == -1 || high == str.length())
                break;
        }

        string palindrome = str.substr(low + 1, high - low - 1);
        if (palindrome.length() > LPS.length())
        {

            LPS = palindrome;
        }

        low = i - 1;
        high = i;
        while (str[low] == str[high])
        {
            low--;
            high++;

            if (low == -1 || high == str.length())
                break;
        }

        palindrome = str.substr(low + 1, high - low - 1);
        if (palindrome.length() > LPS.length())
        {

            LPS = palindrome;
        }
    }

    return LPS;
}

int main()
{
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << longestPalindrome(input) << endl;
    return 0;
}
