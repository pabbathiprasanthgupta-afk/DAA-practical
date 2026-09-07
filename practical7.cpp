#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cin >> amount;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    if (dp[amount] == INT_MAX)
        cout << "Change cannot be made";
    else
        cout << "Minimum number of coins: " << dp[amount];

    return 0;
}
