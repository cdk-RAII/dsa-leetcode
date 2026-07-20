#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector height. The outer while loop
// advances leftMost from left to right. During each iteration, the first inner while loop moves
// the right pointer only to the right until it either finds a bar at least as tall as the current
// left boundary or reaches rightMost. If no such bar exists, the second inner while loop scans
// backward from rightMost to leftMost exactly once to compute the trapped water using the tallest
// bar on the right, after which the algorithm terminates. Since every array index is visited at
// most once by the forward scan and at most once by the final backward scan, the total work is
// O(n + n) ~ O(n).
// Space Complexity: O(1), where n is the size of the input vector height. The algorithm uses only
// a constant amount of extra space for a few integer variables (leftMost, rightMost, left, right,
// trapWater, tempTrapWater, and rightMaxHeight). No additional data structures whose size depends
// on n are allocated.

class Solution {
  public:
    int trap(vector<int>& height) {
        int leftMost = 0;
        int rightMost = static_cast<int>(height.size()) - 1;
        int trapWater = 0;
        while (leftMost < rightMost) {
            int left = leftMost;
            int right = left + 1;
            int tempTrapWater = 0;
            while (right < rightMost && height[right] < height[left]) {
                tempTrapWater += height[left] - height[right];
                right++;
            }
            if (height[right] >= height[left]) {
                trapWater += tempTrapWater;
                leftMost = right;
            } else {
                int rightMaxHeight = height[right];
                while (right > left) {
                    rightMaxHeight = max(rightMaxHeight, height[right]);
                    trapWater += rightMaxHeight - height[right];
                    right--;
                }
                break;
            }
        }
        return trapWater;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    // Find the trapped water
    int result = solution.trap(height);

    // Print the result
    cout << result << "\n";

    return 0;
}