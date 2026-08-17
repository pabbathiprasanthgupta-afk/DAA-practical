#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& p, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] +
                           dp[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int result = matrixChainMultiplication(p, n + 1);

    cout << "Minimum number of scalar multiplications = "
         << result << endl;

    return 0;
}
