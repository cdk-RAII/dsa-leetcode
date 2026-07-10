#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + m) ~ O(n), where n is nums.size() and m is the number of distinct
// elements in nums. Building the frequency map costs O(n): one O(1) amortized unordered_map
// increment per element. The second loop then iterates over frequency's m entries, checking
// count > thresholdFrequency and pushing matches into result - O(m). Since m <= n, the total
// simplifies to O(n).
// Space Complexity: O(m) ~ O(n). frequency.reserve(nums.size()) pre-allocates for the worst case
// (all n elements distinct), so frequency can hold up to m <= n distinct keys. result itself is
// O(1) extra: by the pigeonhole principle, at most 2 elements can have a count exceeding n/3, so
// result never grows past 2 entries regardless of n - it's frequency's O(n) map that dominates.

// class Solution {
//   public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> result;
//         result.reserve(nums.size());
//         int thresholdFrequency = static_cast<int>(nums.size()) / 3;
//         unordered_map<int, int> frequency;
//         frequency.reserve(nums.size());
//         for (const auto& num : nums) {
//             frequency[num]++;
//         }
//         for (const auto& [num, count] : frequency) {
//             if (count > thresholdFrequency) {
//                 result.push_back(num);
//             }
//         }
//         return result;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is nums.size(). The first loop makes a single pass to
// find at most two candidates, doing O(1) work per element (comparisons and counter
// increments/decrements) - O(n). The second loop makes another single pass to verify the true
// counts of candidate0 and candidate1 - also O(n), since a candidate surviving the first pass is
// not guaranteed to actually exceed the n/3 threshold (it must be re-checked). Two sequential O(n)
// passes sum to O(n).
// Space Complexity: O(1). Only a fixed, constant number of scalar variables are used
// (candidate0/1, counter0/1, checkCandidate0/1) plus candidates, which is reserved to capacity 2
// and never grows beyond that - none of this scales with n, unlike Solution 1's O(n) hash map.

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> candidates;
        candidates.reserve(2);
        int numsSize = static_cast<int>(nums.size());
        int thresholdFrequency = numsSize / 3;
        int candidate0 = 0;
        int candidate1 = 0;
        int counter0 = 0;
        int counter1 = 0;

        // Here auto is "int"
        for (const auto& num : nums) {
            if (num == candidate0) {
                counter0++;
            } else if (num == candidate1) {
                counter1++;
            } else if (counter0 == 0) {
                candidate0 = num;
                counter0++;
            } else if (counter1 == 0) {
                candidate1 = num;
                counter1++;
            } else {
                counter0--;
                counter1--;
            }
        }

        int checkCandidate0 = 0;
        int checkCandidate1 = 0;

        // Here auto is "int"
        for (const auto& num : nums) {
            if (num == candidate0) {
                checkCandidate0++;
            } else if (num == candidate1) {
                checkCandidate1++;
            }
        }

        if (checkCandidate0 > thresholdFrequency) {
            candidates.push_back(candidate0);
        }
        if (checkCandidate1 > thresholdFrequency) {
            candidates.push_back(candidate1);
        }

        return candidates;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {3, 2, 3};

    // Find the majority element
    vector<int> result = solution.majorityElement(nums);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}