#include <iostream>
#include <vector>

using namespace std;

// Complxity Analysis:
// Time Complexity: O(m * n) for the constructor, where m is the number of rows and n is the number
// of columns in the matrix. The sumRegion method has a time complexity of O(1).
// Space Complexity: O(m * n) for storing the prefix summed matrix.
class NumMatrix {
  public:
    vector<vector<int>> prefixSummedMatrix;
    NumMatrix(vector<vector<int>>& matrix)
        : prefixSummedMatrix(static_cast<int>(matrix.size()),
                             vector<int>(static_cast<int>(matrix[0].size()), 0)) {
        int matrixRows = static_cast<int>(matrix.size());
        int matrixColumns = static_cast<int>(matrix[0].size());
        int leftSum = 0;
        int upperSum = 0;
        int diagonalSum = 0;

        for (int i = 0; i < matrixRows; ++i) {
            upperSum = 0;
            for (int j = 0; j < matrixColumns; ++j) {
                leftSum = 0;
                diagonalSum = 0;

                if (i > 0 && j > 0) {
                    leftSum = prefixSummedMatrix[i][j - 1];
                    upperSum = prefixSummedMatrix[i - 1][j];
                    diagonalSum = prefixSummedMatrix[i - 1][j - 1];
                } else if (j - 1 < 0 && i > 0) {
                    upperSum = prefixSummedMatrix[i - 1][j];
                } else if (i - 1 < 0 && j > 0) {
                    leftSum = prefixSummedMatrix[i][j - 1];
                }

                prefixSummedMatrix[i][j] = matrix[i][j] + leftSum + upperSum - diagonalSum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int initialSum = prefixSummedMatrix[row2][col2];
        int mainMatrixSum = 0;
        int leftSum = 0;
        int upperSum = 0;
        int diagonalSum = 0;

        if (row1 > 0 && col1 > 0) {
            leftSum = prefixSummedMatrix[row2][col1 - 1];
            upperSum = prefixSummedMatrix[row1 - 1][col2];
            diagonalSum = prefixSummedMatrix[row1 - 1][col1 - 1];
        } else if (col1 - 1 < 0 && row1 > 0) {
            upperSum = prefixSummedMatrix[row1 - 1][col2];
        } else if (row1 - 1 < 0 && col1 > 0) {
            leftSum = prefixSummedMatrix[row2][col1 - 1];
        }

        mainMatrixSum = initialSum - leftSum - upperSum + diagonalSum;

        return mainMatrixSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    // Create a 2D vector (matrix) for testing
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};

    // Create an instance of the NumMatrix class
    NumMatrix* obj = new NumMatrix(matrix);

    // Test sumRegion method
    int result1 = obj->sumRegion(2, 1, 4, 3); // Example query
    int result2 = obj->sumRegion(1, 1, 2, 2); // Example query
    int result3 = obj->sumRegion(1, 2, 2, 4); // Example query

    // Print the results
    cout << "Sum Region (2,1) to (4,3): " << result1 << "\n";
    cout << "Sum Region (1,1) to (2,2): " << result2 << "\n";
    cout << "Sum Region (1,2) to (2,4): " << result3 << "\n";

    // Clean up
    delete obj;

    return 0;
}