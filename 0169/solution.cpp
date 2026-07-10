#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is nums.size(). We scan nums once, and each iteration does O(1)
// amortized unordered_map work (frequency[num]++ and the lookup in the if condition share the same
// bucket). The early break() only helps in the average case - the worst-case bound is still O(n),
// since the majority element's count can cross thresholdFrequency as late as the final iteration,
// depending on how its occurrences are distributed through nums.
// Space Complexity: O(n). Because the problem guarantees a majority element exists (> n/2
// occurrences), the remaining minority elements can number at most ~n/2, but that's still O(n)
// distinct keys frequency can hold in the worst case before the majority element crosses the
// threshold.

// class Solution {
//   public:
//     int majorityElement(vector<int>& nums) {
//         int result = 0;
//         int thresholdFrequency = static_cast<int>(nums.size()) / 2;
//         unordered_map<int, int> frequency;
//         frequency.reserve(nums.size());

//         // Here auto is "int"
//         for (const auto& num : nums) {
//             frequency[num]++;
//             if (frequency[num] > thresholdFrequency) {
//                 result = num;
//                 break;
//             }
//         }

//         return result;
//     }
// };

// Complexity Analysis:
// Boyer-Moore voting algorithm
// Time Complexity: O(n), where n is nums.size(). A single pass over nums, with O(1) work per
// iteration (one comparison and one increment/decrement of counter) - no early exit is needed or
// used, since the algorithm relies on the guarantee that a true majority element exists to end up
// as the surviving candidate after cancelling out against every other value.
// Space Complexity: O(1). Only candidate and counter are used; no data structure scales with n,
// unlike Solution 1's hash map.

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int counter = 0;

        // Here auto is "int"
        for (const auto& num : nums) {
            if (num == candidate) {
                counter++;
            } else if (counter == 0) {
                candidate = num;
                counter++;
            } else {
                counter--;
            }
        }

        return candidate;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // Find the majority element
    int result = solution.majorityElement(nums);

    // Print the result
    cout << result << "\n";

    return 0;
}