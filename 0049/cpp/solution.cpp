#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsMap;
        anagramsMap.reserve(strs.size());
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramsMap[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        result.reserve(anagramsMap.size());
        // Here auto is pair<const string, vector<string>>
        for (const auto& [_, anagramsGroup] : anagramsMap) {
            result.push_back(anagramsGroup);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    int resultSize = static_cast<int>(result.size());
    cout << "[";
    for (int i = 0; i < resultSize; ++i) {
        int groupS = static_cast<int>(result[i].size());
        cout << "[";
        for (int j = 0; j < groupS; ++j) {
            cout << "\"" << result[i][j] << "\"";
            if (j + 1 < groupS) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i + 1 < resultSize) {
            cout << ", ";
        }
    }
    cout << "]\n";
    return 0;
}