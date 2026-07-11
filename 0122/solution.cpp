#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is prices.size(). A single pass compares each adjacent pair
// (prices[i], prices[i - 1]), doing O(1) work per iteration (one comparison and at most one
// addition into profit) - no nested loops or extra passes are needed since every profitable
// day-to-day increase can simply be accumulated greedily.
// Space Complexity: O(1). Only profit and the loop index are used; no data structure scales
// with n.

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
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