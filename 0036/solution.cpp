#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(1) for a fixed 9x9 board (81 cells, each doing bounded work). Generalizing to
// an N x N board: the nested loop runs N^2 times, and each iteration does up to three
// string::contains(char) checks - a linear scan of a string that can grow up to N characters (one
// per row/column/box), costing O(N) each. So each cell costs O(N), for a generalized total of
// O(N^2 * N) = O(N^3). At the fixed N = 9, O(N^3) = O(729) = O(1).
// Space Complexity: O(1) for a fixed 9x9 board. Generalizing to N x N: rows, columns, and boxes
// each hold N strings that together sum to at most N characters per row/column/box, i.e., O(N^2)
// characters total per map, so O(N^2) overall (three maps of O(N^2) each). At N = 9, this is O(1).

// class Solution {
//   public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_map<int, string> rows;
//         unordered_map<int, string> columns;
//         unordered_map<int, string> boxes;

//         for (int i = 0; i < 9; ++i) {
//             for (int j = 0; j < 9; ++j) {
//                 int boxRow = i / 3;
//                 int boxColumn = j / 3;
//                 int boxIndex = (3 * boxRow) + boxColumn;

//                 if (board[i][j] == '.') {
//                     continue;
//                 }

//                 if (rows[i].contains(board[i][j]) || columns[j].contains(board[i][j]) ||
//                     boxes[boxIndex].contains(board[i][j])) {
//                     return false;
//                 }

//                 rows[i].push_back(board[i][j]);
//                 columns[j].push_back(board[i][j]);
//                 boxes[boxIndex].push_back(board[i][j]);
//             }
//         }

//         return true;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(1) for a fixed 9x9 board. Generalizing to an N x N board: the nested loop
// runs N^2 times, and each iteration does O(1) work - direct boolean array indexing
// (rows[i][charToIntAdjusted], etc.) instead of a string scan, unlike Solution 1. So the
// generalized total is O(N^2), which is asymptotically better than Solution 1's O(N^3). At N = 9,
// O(N^2) = O(81) = O(1).
// Space Complexity: O(1) for a fixed 9x9 board. Generalizing to N x N: rows, columns, and boxes
// are each N x N boolean grids, so O(N^2) per grid, O(N^2) overall (same order as Solution 1, just
// with a smaller constant factor since bool storage beats a string per row/column/box).

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> columns(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                int boxRow = i / 3;
                int boxColumn = j / 3;
                int boxIndex = (3 * boxRow) + boxColumn;
                // Convert the character to an integer in the range 0-8 (for '1'-'9') by subtracting
                // '1'
                int charToIntAdjusted = board[i][j] - '1';

                if (board[i][j] == '.') {
                    continue;
                }

                if (rows[i][charToIntAdjusted] == true || columns[j][charToIntAdjusted] == true ||
                    boxes[boxIndex][charToIntAdjusted] == true) {
                    return false;
                }

                rows[i][charToIntAdjusted] = true;
                columns[j][charToIntAdjusted] = true;
                boxes[boxIndex][charToIntAdjusted] = true;
            }
        }

        return true;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // Check if the Sudoku board is valid
    bool result = solution.isValidSudoku(board);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}