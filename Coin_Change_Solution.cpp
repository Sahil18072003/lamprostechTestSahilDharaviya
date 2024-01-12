#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoins(vector<int> &coins, int target)
{
    int n = coins.size();

    // Create a table to store the minimum number of coins needed for each amount
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0; // Zero coins needed for zero amount

    // Iterate through each coin denomination
    for (int i = 1; i <= n; ++i)
    {
        for (int j = coins[i - 1]; j <= target; ++j)
        {
            // Update the minimum number of coins needed for the current amount
            if (dp[j - coins[i - 1]] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 2);
            }
        }
    }

    // If dp[target] is still INT_MAX, it means the target amount cannot be formed
    return (dp[target] == INT_MAX) ? -1 : dp[target];
}

int main()
{
    // Example usage
    vector<int> denominations = {1, 5, 10};
    int targetAmount = 27;

    int result = minCoins(denominations, targetAmount);

    // Display the minimum number of coins needed
    if (result != -1)
    {
        cout << "Minimum number of coins needed: " << result << endl;
    }
    else
    {
        cout << "It's not possible." << endl;
    }

    return 0;
}
