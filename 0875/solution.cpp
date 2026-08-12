#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n log(maxP - minK)) ~ O(n log(maxP)), where n is the number of piles and
// maxP is the maximum number of bananas in any pile. The first for loop calculates totalBans and
// maxBans1Pil by visiting all n piles, costing O(n). The binary search then searches the eating
// speed range [minK, maxK]. The search range is approximately halved in every iteration, so it
// performs O(log(maxP - minK)) iterations. During each binary-search iteration, the second for
// loop checks the required hours for the piles and performs O(n) work in the worst case. Therefore,
// the binary-search phase costs O(n log(maxP - minK)). Summing both phases gives
// O(n + n log(maxP - minK)) ~ O(n log(maxP)).
// Space Complexity: O(1), where n is the number of piles. The algorithm uses only a constant
// amount of extra space for variables such as pilesSize, maxBans1Pil, totalBans, k, minK, maxK,
// searchSize, midpoint, and hSpent. No additional data structures whose size depends on n are
// allocated.

class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesSize = static_cast<int>(piles.size());
        int maxBans1Pil = piles[0];
        long long totalBans = 0;

        for (const int& bans : piles) {
            totalBans += bans;
            maxBans1Pil = max(bans, maxBans1Pil);
        }

        int k = maxBans1Pil;

        if (pilesSize == h) {
            return k;
        }

        // The standard solution takes minK = 1, but I can optimize it to minK = ceil(totalBans / h)
        // because if k < ceil(totalBans / h), then the total hours spent eating all the bananas
        // will exceed h, which is not allowed. Therefore, the minimum ceil(totalBans / h) ==
        // static_cast<int>((totalBans + h - 1) / h)
        int minK = static_cast<int>((totalBans + h - 1) / h);
        int maxK = maxBans1Pil;

        while (maxK >= minK) {
            int searchSize = maxK - minK;
            int midpoint = minK + searchSize / 2;
            long long hSpent = 0;

            for (const int& bans : piles) {
                // ceil(bans / midpoint) == static_cast<int>((bans + midpoint - 1) / midpoint)
                hSpent = hSpent + static_cast<long long>((bans + midpoint - 1) / midpoint);

                if (hSpent > h) {
                    break;
                }
            }

            if (hSpent <= h) {
                k = midpoint;
                maxK = midpoint - 1;
            } else {
                minK = midpoint + 1;
            }
        }

        return k;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> height = {34392671, 891616382, 813261297};
    int h = 712127987;

    // Find the maximum area
    int result = solution.minEatingSpeed(height, h);

    // Print the result
    cout << result << "\n";

    return 0;
}