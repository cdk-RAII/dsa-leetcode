#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the size of the input vector heights. The for loop iterates
// through all n bars once, plus one additional sentinel iteration (i == heightsSize), which is
// still O(n). Each index is pushed onto indexStack exactly once and popped from it at most once.
// Every call to updateMaxRectangle() performs only O(1) work (pop, arithmetic operations, and
// max()). Therefore, the total number of stack operations is O(n + n) ~ O(n), giving an overall
// time complexity of O(n).
// Space Complexity: O(n), where n is the size of the input vector heights. In the worst case
// (e.g., when the histogram heights are in non-decreasing order), every index is pushed onto
// indexStack before any are popped. Thus, the stack may grow to hold all n indices, requiring
// O(n) auxiliary space.

class Solution {
  private:
    void updateMaxRectangle(const vector<int>& heights, stack<int>& indexStack, int rightLimit,
                            int& maxRectangleArea) {
        const int heightIdx = indexStack.top();
        indexStack.pop();
        const int leftLimit = indexStack.empty() ? 0 : indexStack.top() + 1;
        const int width = rightLimit - leftLimit + 1;
        const int rectangleArea = width * heights[heightIdx];
        maxRectangleArea = max(maxRectangleArea, rectangleArea);
    }

  public:
    int largestRectangleArea(vector<int>& heights) {
        const int heightsSize = static_cast<int>(heights.size());
        stack<int> indexStack;
        int rightLimit = 0;
        int maxRectangleArea = 0;

        for (int i = 0; i <= heightsSize; ++i) {
            while (!indexStack.empty() &&
                   (i == heightsSize || heights[i] < heights[indexStack.top()])) {
                rightLimit = (i == heightsSize) ? heightsSize - 1 : i - 1;
                updateMaxRectangle(heights, indexStack, rightLimit, maxRectangleArea);
            }

            indexStack.push(i);
        }

        return maxRectangleArea;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> height = {2, 1, 5, 6, 2, 3};

    // Find the largest rectangle area
    int result = solution.largestRectangleArea(height);

    // Print the result
    cout << result << "\n";

    return 0;
}