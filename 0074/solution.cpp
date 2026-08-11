#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(log(m * n)), where m is the number of rows and n is the number of columns
// in the matrix. The matrix is treated as a logically flattened one-dimensional sorted array
// containing m * n elements. The while loop performs binary search over this range, reducing the
// search space approximately by half in every iteration. Each iteration performs O(1) work,
// including calculating the midpoint, converting the 1D index into a 2D index, and comparing the
// matrix element with target. Therefore, the total time complexity is O(log(m * n)).
// Space Complexity: O(1), where m is the number of rows and n is the number of columns in the
// matrix. The algorithm uses only a constant amount of extra space for variables such as rows,
// cols, start, end, searchSize, midpoint, and midpoint2D. The intoP2DIdx() function also returns
// only a pair of two integers. No additional data structures whose size depends on m or n are
// allocated.

class Solution {
  private:
    pair<int, int> intoP2DIdx(const int idx1D, const int cols) {
        return {idx1D / cols, idx1D % cols};
    }

  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        int start = 0;
        int end = rows * cols - 1;

        while (end >= start) {
            const int searchSize = end - start;
            const int midpoint = start + searchSize / 2;
            const pair<int, int> midpoint2D = intoP2DIdx(midpoint, cols);

            if (matrix[midpoint2D.first][midpoint2D.second] == target) {
                return true;
            } else if (matrix[midpoint2D.first][midpoint2D.second] < target) {
                start = midpoint + 1;
            } else {
                end = midpoint - 1;
            }
        }

        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;

    // Check if the target is in the matrix
    bool result = solution.searchMatrix(matrix, target);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}