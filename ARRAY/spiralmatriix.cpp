#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty())
        {
            return result;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        int left=0;
        int top=0;
        int right = m - 1;
        int bottom = n - 1;
        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; ++i)
            {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

        solution s1;
    vector<int> spiralTraversal = s1.spiralOrder(matrix);

    cout << "Spiral Traversal: ";
    for (int val : spiralTraversal)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
