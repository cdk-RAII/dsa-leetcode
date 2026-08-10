#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the number of operations in the input vector operations. The
// for loop processes each operation exactly once, and each operation performs only O(1) work.
// Accessing the last one or two elements of scores, emplace_back(), pop_back(), and updating sum
// all take O(1) time. The stoi() conversion also takes O(1) time here because each operation
// represents an integer bounded by the problem constraints. Therefore, the total time complexity
// is O(n).
// Space Complexity: O(n), where n is the number of operations in the input vector operations. The
// scores vector stores the valid scores. In the worst case, when every operation adds a new score,
// scores can contain n elements. Therefore, the auxiliary space complexity is O(n).

class Solution {
  public:
    int calPoints(vector<string>& operations) {
        // Here vector scores is used as stack to store the valid scores.
        vector<int> scores;
        scores.reserve(operations.size());
        int sum = 0;

        for (const string& opt : operations) {
            if (opt == "C") {
                sum -= scores.back();
                scores.pop_back();
            } else if (opt == "D") {
                scores.emplace_back(2 * scores.back());
                sum += scores.back();
            } else if (opt == "+") {
                scores.emplace_back(scores.back() + scores[scores.size() - 2]);
                sum += scores.back();
            } else {
                scores.emplace_back(stoi(opt));
                sum += scores.back();
            }
        }

        return sum;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<string> operations = {"5", "2", "C", "D", "+"};

    // Calculate the points
    int result = solution.calPoints(operations);

    // Print the result
    cout << result << "\n";

    return 0;
}