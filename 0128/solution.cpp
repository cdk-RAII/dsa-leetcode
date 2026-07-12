#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + m + m) ~ O(n), where n is nums.size() and m is the number of unique
// elements in nums (m <= n). Inserting all n elements into numsSet costs O(n) amortized
// average-case (worst case O(n^2) under hash collisions, though rare in practice). The outer loop
// runs exactly m times (once per unique element). The inner while loop only starts from true
// sequence starts (guarded by the "seqStart - 1 not in set" check), so each element is visited by
// at most one while-loop run across the entire algorithm, making the total inner-loop work O(m).
// Since m <= n, this simplifies to O(n).
// Space Complexity: O(n) (more precisely O(m)), where n is nums.size(). In the worst case (no
// duplicates), numsSet grows to hold all n elements.
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        int sequenceLength = 0;
        std::unordered_set<int> numsSet;
        numsSet.reserve(nums.size());
        numsSet.insert(nums.begin(), nums.end());

        // Here auto is "int"
        for (const auto& num : numsSet) {
            int seqLenTemp = 1;
            int seqStart = num;

            if (numsSet.contains(seqStart - 1)) {
                continue;
            }

            while (numsSet.contains(seqStart + 1)) {
                seqLenTemp++;
                seqStart++;
            }

            if (seqLenTemp > sequenceLength) {
                sequenceLength = seqLenTemp;
            }
        }

        return sequenceLength;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Find the longest consecutive sequence
    int result = solution.longestConsecutive(nums);

    // Print the result
    cout << result << "\n";

    return 0;
}