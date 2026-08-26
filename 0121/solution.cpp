#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
//
// Time Complexity: O(n).
//
// The algorithm performs one pass over prices from index 1 to n - 1.
// For each price, it performs two O(1) operations:
//
// 1. minPrice = min(prices[i], minPrice)
//    Updates the minimum stock price seen so far.
//
// 2. profit = max(prices[i] - minPrice, profit)
//    Updates the maximum profit obtainable by selling on the current day.
//
// Each element is processed exactly once, so the total work is O(n).
// There are no nested loops, sorting operations, recursion, or other
// input-dependent operations.
//
// Therefore:
// Time Complexity: O(n).
//
// Space Complexity: O(1).
//
// The algorithm uses only a constant number of scalar variables:
// pricesS, profit, minPrice, and the loop variable i.
// No additional data structure grows with the input size.
//
// Therefore:
// Auxiliary Space Complexity: O(1).

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int pricesS = static_cast<int>(prices.size());
        int profit = 0;
        int minPrice = prices[0];

        for (int i = 1; i < pricesS; ++i) {
            minPrice = min(prices[i], minPrice);
            profit = max(prices[i] - minPrice, profit);
        }

        return profit;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Find the maximum profit
    int result = solution.maxProfit(prices);

    // Print the result
    cout << result << "\n";

    return 0;
}