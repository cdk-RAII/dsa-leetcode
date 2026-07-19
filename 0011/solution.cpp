#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector height. The left pointer starts
// at the beginning of the array and the right pointer starts at the end. In every iteration of the
// loop, the algorithm computes the current area in O(1) time and then moves exactly one pointer
// one position toward the other. Since each pointer can move at most n - 1 times, the total number
// of pointer movements is at most n - 1. Therefore, the algorithm performs a single linear scan of
// the array, giving O(n) time.
// Space Complexity: O(1), where n is the size of the input vector height. The algorithm uses only
// a constant amount of extra space for a few integer variables (left, right, mArea, currentArea,
// width, and length). No additional data structures whose size depends on n are allocated.

class Solution {
  public:
    int areaCalculator(const vector<int>& height, int& left, int& right) {
        int width = min(height[left], height[right]);
        int length = right - left;

        return width * length;
    }
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int mArea = 0;

        while (left < right) {
            int currentArea = areaCalculator(height, left, right);
            mArea = max(mArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return mArea;
    }
};

// This my implementation.
// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector height. The initial
// areaCalculator() call costs O(1). During the algorithm, the left pointer only moves to the
// right, and the right pointer only moves to the left. Although there are nested while loops that
// skip over heights which cannot produce a larger area, each array index is visited by the left
// pointer at most once and by the right pointer at most once. Every subsequent call to
// areaCalculator() also costs O(1). Therefore, the total number of pointer movements across the
// entire algorithm is at most n - 1, giving O(n) time.
// Space Complexity: O(1), where n is the size of the input vector height. The algorithm uses only
// a constant amount of extra space for a few integer variables (left, right, tempLeft,
// tempRight, mArea, leftArea, rightArea, width, and length). No additional data structures whose
// size depends on n are allocated.

class Solution {
  public:
    int areaCalculator(const vector<int>& height, int& left, int& right) {
        int width = min(height[left], height[right]);
        int length = right - left;

        return width * length;
    }

    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int mArea = areaCalculator(height, left, right);

        while (left < right) {
            if (height[left] <= height[right]) {
                int tempLeft = left + 1;

                while (tempLeft < right && height[left] >= height[tempLeft]) {
                    tempLeft++;
                }

                left = tempLeft;
                int leftArea = areaCalculator(height, left, right);
                mArea = max(mArea, leftArea);

                continue;
            }

            if (height[left] >= height[right]) {
                int tempRight = right;

                while (tempRight > left && height[right] >= height[tempRight]) {
                    tempRight--;
                }

                right = tempRight;
                int rightArea = areaCalculator(height, left, right);
                mArea = max(mArea, rightArea);

                continue;
            }
        }

        return mArea;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> height = {2, 3, 10, 5, 7, 8, 9};

    // Find the maximum area
    int result = solution.maxArea(height);

    // Print the result
    cout << result << "\n";

    return 0;
}