#include <algorithm>
#include <iostream>
#include <ranges>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n log n + n) ~ O(n log n), where n is the number of cars. The first
// range-based for loop iterates through all n cars and constructs the kinematics vector, requiring
// O(n) time. The ranges::sort() operation sorts all n elements and requires O(n log n) time. The
// second range-based for loop iterates through all n sorted cars. For each car, the algorithm
// performs O(1) work, including the division and at most one stack push, giving O(n) time.
// Therefore, the total time complexity is O(n + n log n + n) ~ O(n log n).
// Space Complexity: O(n + n) ~ O(n), where n is the number of cars. The kinematics vector stores
// n pairs and therefore requires O(n) space. The time stack can contain at most n fleet arrival
// times, requiring O(n) space in the worst case. The sorting algorithm itself may also use O(log n)
// stack space, but this is dominated by the O(n) space already required by kinematics and time.
// Therefore, the total auxiliary space complexity is O(n + n + log n) ~ O(n).

class Solution {
  public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int pstSize = static_cast<int>(position.size());
        vector<pair<int, int>> kinematics;
        kinematics.reserve(pstSize);
        stack<double> time;

        for (const auto& [pst, spd] : views::zip(position, speed)) {
            kinematics.emplace_back(target - pst, spd);
        }

        sort(kinematics.begin(), kinematics.end());

        for (const auto& [pst, spd] : kinematics) {
            if (time.empty() || static_cast<double>(pst) / spd > time.top()) {
                time.push(static_cast<double>(pst) / spd);
            }
        }

        return static_cast<int>(time.size());
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    // Find the number of car fleets
    int result = solution.carFleet(target, position, speed);

    // Print the result
    cout << result << "\n";

    return 0;
}