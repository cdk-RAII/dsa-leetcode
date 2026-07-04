#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n * k log k), where n is the number of strings in the input vector strs, and k
// is the maximum length of a string in strs. We iterate through each string in strs, and for each
// string, we sort its characters, which takes O(k log k) time. Space Complexity: O(n * k), where n
// is the number of strings in strs, and k is the maximum length of a string in strs. We store the
// grouped anagrams in a vector of vectors, which can take up to O(n * k) space in the worst case.
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() > 1) {
            vector<vector<string>> result;
            result.reserve(strs.size());
            unordered_map<string, vector<string>> anagramsMap;
            anagramsMap.reserve(strs.size());
            string tempSort;

            for (size_t i = 0; i < strs.size(); ++i) {
                // First we copy the string to a temporary variable, then we sort it to use as a key
                // in the map, then we push the original string into the vector corresponding to
                // that key in the map.
                tempSort = strs[i];
                sort(tempSort.begin(), tempSort.end());
                anagramsMap[tempSort].push_back(strs[i]);
            }

            // Here auto is "pair<const string, vector<string>>"
            for (const auto& [word, anagrams] : anagramsMap) {
                result.push_back(anagrams);
            }

            return result;
        }

        return {{strs[0]}};
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Group anagrams
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << "\"" << result[i][j] << "\"";
            if (j + 1 < result[i].size()) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i + 1 < result.size()) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}