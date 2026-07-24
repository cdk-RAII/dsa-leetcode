#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the number of elements in the input vector tokens. The
// algorithm iterates through tokens exactly once. For each token, isOperator() performs at most
// four string comparisons, each taking O(1) because every operator string has length 1. If the
// token is an operand, stoi() converts a string whose maximum length is bounded by the problem
// constraints (at most "-200"), so it also runs in O(1) time. Each stack operation (push, pop,
// and top) takes O(1) time. Therefore, each iteration performs only constant-time work, giving
// O(n) time.
// Space Complexity: O(n), where n is the number of elements in the input vector tokens. In the
// worst case, the stack stores all operands before any operators are encountered (e.g., a valid
// expression with many operands followed by operators). Thus, the stack may grow to O(n)
// elements, requiring O(n) auxiliary space.

class Solution {
  public:
    bool isOperator(const string& str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }

    void operation(stack<int>& tok, const string& optr) {
        int var1 = tok.top();
        tok.pop();
        int var2 = tok.top();
        tok.pop();

        if (optr == "+") {
            tok.push(var2 + var1);
        } else if (optr == "-") {
            tok.push(var2 - var1);
        } else if (optr == "*") {
            tok.push(var2 * var1);
        } else {
            tok.push(var2 / var1);
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> tok;

        for (const string& str : tokens) {
            if (isOperator(str)) {
                operation(tok, str);
            } else {
                tok.push(stoi(str));
            }
        }

        return tok.top();
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<string> tokens = {"2", "1", "+", "3", "*"};

    // Evaluate Reverse Polish Notation
    int result = solution.evalRPN(tokens);

    // Print the result
    cout << result << "\n";

    return 0;
}