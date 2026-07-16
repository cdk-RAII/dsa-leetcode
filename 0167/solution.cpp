#include <iostream>
#include <vector>

using namespace std;

// This solution only if guaranteed that there is exactly one solution.
// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector numbers. Although there are nested
// while loops, they do not cause quadratic time. The left pointer only moves to the right, and the
// right pointer only moves to the left. Across the entire execution, each pointer advances at most
// n - 1 times, so the total number of pointer movements is at most n - 1. Therefore, the algorithm
// still performs a single linear scan of the array, giving O(n) time.
// Space Complexity: O(1), where n is the size of the input vector numbers. The algorithm uses only
// a few integer variables (left and right). The returned vector always contains exactly two
// integers, so it occupies constant space and is not counted as auxiliary space.

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            }

            while (numbers[left] + numbers[right] > target) {
                right--;
            }

            while (numbers[left] + numbers[right] < target) {
                left++;
            }
        }

        return {left + 1, right + 1};
    }
};

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector numbers. The left pointer starts
// at the beginning of the array and the right pointer starts at the end. In every iteration of the
// loop, exactly one pointer moves closer to the other by one position. Since each pointer can move
// at most n - 1 times, the total number of pointer movements is at most n - 1. Therefore, the
// algorithm performs a single linear scan of the array, giving O(n) time.
// Space Complexity: O(1), where n is the size of the input vector numbers. The algorithm uses only
// a few integer variables (left, right, and sum). The returned vector always contains exactly two
// integers, so it occupies constant space and is not counted as auxiliary space.

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = static_cast<int>(numbers.size()) - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }

        return {};
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Find the two sum
    vector<int> result = solution.twoSum(nums, target);

    // Print the result
    cout << "[" << result[0] << ", " << result[1] << "]\n";

    return 0;
}