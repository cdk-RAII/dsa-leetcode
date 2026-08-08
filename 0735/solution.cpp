#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Initially, I wrote this solution.
// Complexity Analysis:
// Time Complexity: O(n + n + n + n) ~ O(n), where n is the size of the input vector asteroids. The
// outer for loop processes all n asteroids, giving O(n) time. Although the while loop may perform
// multiple collision checks for a single asteroid, every asteroid can be pushed onto the stack at
// most once and popped from the stack at most once. Therefore, all collision pops contribute O(n)
// work across the entire execution. The final while loop transfers each remaining asteroid from
// the stack to result, requiring O(n) time. Finally, reverse() processes at most n elements,
// requiring O(n) time. Therefore, the total time complexity is O(n + n + n + n) ~ O(n).
// Space Complexity: O(n + n) ~ O(n), where n is the size of the input vector asteroids. The
// asteroid stack can contain at most n elements, requiring O(n) space. The result vector can also
// contain at most n elements and therefore requires O(n) space. Thus, the total auxiliary space
// complexity is O(n + n) ~ O(n).

class Solution {
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        const int asteroidsSize = static_cast<int>(asteroids.size());
        stack<int> asteroid;
        vector<int> result;
        result.reserve(asteroidsSize);

        for (const int& atd : asteroids) {
            if (asteroid.empty() || !(asteroid.top() > 0 && atd < 0)) {
                asteroid.push(atd);
            } else {
                while (!asteroid.empty() && asteroid.top() > 0 && asteroid.top() + atd < 0) {
                    asteroid.pop();
                }

                if (asteroid.empty() || asteroid.top() < 0) {
                    asteroid.push(atd);
                } else if (asteroid.top() + atd == 0) {
                    asteroid.pop();
                }
            }
        }

        while (!asteroid.empty()) {
            result.push_back(asteroid.top());
            asteroid.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

// Then I rewrote the solution to make it more readable and easier to understand.
// Complexity Analysis:
// Time Complexity: O(n + n + n + n) ~ O(n), where n is the size of the input vector asteroids. The
// outer for loop processes all n asteroids, giving O(n) time. Although the while loop may perform
// multiple collision checks for a single asteroid, every asteroid can be pushed onto the stack at
// most once and popped from the stack at most once. Therefore, all collision pops contribute O(n)
// work across the entire execution. The final while loop transfers each remaining asteroid from the
// stack to result, requiring O(n) time. Finally, reverse() processes at most n elements, requiring
// O(n) time. Therefore, the total time complexity is O(n + n + n + n) ~ O(n).
// Space Complexity: O(n + n) ~ O(n), where n is the size of the input vector asteroids. The
// asteroid stack can contain at most n elements, requiring O(n) space. The result vector can also
// contain at most n elements and therefore requires O(n) space. Thus, the total auxiliary space
// complexity is O(n + n) ~ O(n).

class Solution {
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        const int asteroidsSize = static_cast<int>(asteroids.size());
        stack<int> asteroid;
        vector<int> result;
        result.reserve(asteroidsSize);

        for (const int& atd : asteroids) {
            bool nothingLeft = false;

            while (!asteroid.empty() && asteroid.top() > 0 && atd < 0) {
                if (asteroid.top() + atd < 0) {
                    asteroid.pop();
                } else if (asteroid.top() + atd == 0) {
                    asteroid.pop();
                    nothingLeft = true;
                    break;
                } else {
                    nothingLeft = true;
                    break;
                }
            }

            if (!nothingLeft) {
                asteroid.push(atd);
            }
        }

        while (!asteroid.empty()) {
            result.push_back(asteroid.top());
            asteroid.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> asteroids = {3, 5, -6, 2, -1, 4};

    // Find the asteroid collision result
    vector<int> result = solution.asteroidCollision(asteroids);

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