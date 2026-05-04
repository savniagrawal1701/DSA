#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {

        int n = matrix.size();

        for (int k = 0; k < n; k++)
        {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][k] == -1 ||
                        matrix[k][j] == -1)
                        continue;

                    if (matrix[i][j] == -1)
                    {

                        matrix[i][j] =
                            matrix[i][k] + matrix[k][j];
                    }

                    else
                    {
                        matrix[i][j] =
                            min(matrix[i][j],
                                matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
    }
};

int main()
{

    vector<vector<int>> matrix = {
        {0, 2, -1, -1},
        {1, 0, 3, -1},
        {-1, -1, 0, -1},
        {3, 5, 4, 0}};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function to find the shortest distance
    between every pair of vertices. */
    sol.shortest_distance(matrix);

    int n = matrix.size();
    cout << "The shortest distance matrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}