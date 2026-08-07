#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is the size of the input vector temperatures. The
// outer for loop iterates through all n temperatures, giving O(n) work. Although there is a
// nested while loop, each index is pushed onto idxStack exactly once and popped from it at most
// once. Therefore, across the entire execution, the while loop performs at most n pop operations,
// giving O(n) additional work. Each stack operation and each assignment to answer takes O(1) time.
// Thus, the total time complexity is O(n + n) ~ O(n).
// Space Complexity: O(n + n) ~ O(n), where n is the size of the input vector temperatures. The
// answer vector contains n integers and therefore requires O(n) space. In the worst case, when
// temperatures are non-increasing, all n indices are pushed onto idxStack, requiring O(n) space.
// Therefore, the total auxiliary space used is O(n + n) ~ O(n).

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int temperaturesSize = static_cast<int>(temperatures.size());
        vector<int> answer(temperaturesSize);
        stack<int> idxStack;
        for (int i = 0; i < temperaturesSize; ++i) {
            while (!idxStack.empty() && temperatures[i] > temperatures[idxStack.top()]) {
                answer[idxStack.top()] = i - idxStack.top();
                idxStack.pop();
            }
            idxStack.push(i);
        }
        return answer;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    // Find the daily temperatures
    vector<int> result = solution.dailyTemperatures(temperatures);

    // Print the result
    cout << "[";
    for (int i = 0; i < static_cast<int>(result.size()); ++i) {
        cout << result[i];
        if (i < static_cast<int>(result.size()) - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}