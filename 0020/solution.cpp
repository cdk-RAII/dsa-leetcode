#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n), where n is the length of the input string s. The algorithm iterates
// through the string exactly once. For each character, it performs at most one stack operation
// (push or pop), and each stack operation takes O(1) time. Therefore, the total time complexity
// is O(n).
// Space Complexity: O(n), where n is the length of the input string s. In the worst case (e.g.,
// "(((((" or "{{[[("), every character is pushed onto the stack and none are popped until the end.
// Thus, the stack may grow to hold all n characters, requiring O(n) auxiliary space.

class Solution {
  public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (char ch : s) {
            if (parentheses.empty()) {
                parentheses.push(ch);
            } else if ((ch == ')' && parentheses.top() == '(') ||
                       (ch == '}' && parentheses.top() == '{') ||
                       (ch == ']' && parentheses.top() == '[')) {
                parentheses.pop();
            } else {
                parentheses.push(ch);
            }
        }
        return parentheses.empty();
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "()[]{}";

    // Check if the string is valid
    bool result = solution.isValid(s);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}