#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is the length of the input string path. The for loop
// processes each character of path once, giving O(n) time. Although the handling of ".." contains a
// do-while loop that may remove multiple characters from cPath, every character that is removed
// by this loop was previously added to cPath by the main loop. Therefore, across the entire
// execution, each character can be pushed once and removed at most once. The final trailing-slash
// check performs O(1) work. Thus, the total time complexity is O(n + n) ~ O(n).
// Space Complexity: O(n), where n is the length of the input string path. The string cPath can
// contain up to n characters in the worst case, so it requires O(n) auxiliary space. No other
// data structure whose size depends on n is allocated.

class Solution {
  public:
    string simplifyPath(string path) {
        // Here string cPath is used as stack to store the simplified path.
        string cPath;
        cPath.reserve(path.size());

        for (size_t i = 0; i <= path.size(); ++i) {
            if (i < path.size() && path[i] == '/' && cPath.ends_with("/")) {
                continue;
            } else if ((i == path.size() || path[i] == '/') && cPath.ends_with("/.")) {
                cPath.resize(cPath.size() - 1);
            } else if ((i == path.size() || path[i] == '/') && cPath.ends_with("/..")) {
                cPath.resize(cPath.size() - 2);

                do {
                    if (cPath.size() > 1) {
                        cPath.pop_back();
                    }
                } while (!cPath.ends_with("/"));
            } else if (i != path.size()) {
                cPath.push_back(path[i]);
            }
        }

        if (cPath.size() > 1 && cPath.ends_with("/")) {
            cPath.pop_back();
        }

        return cPath;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string path = "/a//b////c/d//././/..";

    // Simplify the path
    string simplifiedPath = solution.simplifyPath(path);

    // Print the result
    cout << simplifiedPath << "\n";

    return 0;
}