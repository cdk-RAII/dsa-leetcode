#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
//
// Time Complexity:
// Expected: O(n)
//
// The algorithm scans nums from left to right once. For each element:
//
// 1. lastIdx.find(nums[i]) performs an expected O(1) hash-table lookup.
// 2. If the value was seen before, the stored index is compared with i,
//    which is O(1).
// 3. lastIdx[nums[i]] = i performs an expected O(1) insertion/update.
//
// Therefore, when unordered_map operations are expected O(1), the loop
// performs O(n) total work.
//
// The call to lastIdx.reserve(numsS) preallocates bucket capacity and
// avoids repeated rehashing as elements are inserted. Its cost is linear
// in the number of buckets/elements being prepared, so it remains within
// the overall O(n) expected bound.
//
// The function may terminate early when it finds a qualifying duplicate.
// Thus the best case is O(1).
//
// The theoretical worst case for unordered_map is O(n) per lookup/update
// if pathological hash collisions occur. In that case, the loop can take
// O(n^2) time overall.
//
// Therefore:
// Expected Time: O(n)
// Worst-Case Time: O(n^2)
//
// Space Complexity: O(n)
//
// lastIdx stores the most recent index for each distinct value in nums.
// In the worst case, all n values are distinct, so the hash table contains
// O(n) entries. reserve(numsS) also allocates O(n) bucket capacity.
//
// Therefore, the auxiliary space complexity is O(n).

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int numsS = static_cast<int>(nums.size());
        unordered_map<int, int> lastIdx;
        lastIdx.reserve(numsS);

        for (int i = 0; i < numsS; ++i) {
            auto it = lastIdx.find(nums[i]);

            if (it != lastIdx.end() && i - it->second <= k) {
                return true;
            }

            lastIdx[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    // Find the target
    bool result = solution.containsNearbyDuplicate(nums, k);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}