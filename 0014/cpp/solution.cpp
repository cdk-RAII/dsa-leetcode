#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsS = static_cast<int>(strs.size());
        if (strs.empty()) {
            return "";
        }
        string prefixStr = strs[0];
        for (int i = 1; i < strsS; ++i) {
            int j = 0;
            int prefixStrS = static_cast<int>(prefixStr.size());
            int strsIS = static_cast<int>(strs[i].size());
            while (j < prefixStrS && j < strsIS && prefixStr[j] == strs[i][j]) {
                ++j;
            }
            prefixStr.erase(j);
            if (prefixStr.empty()) {
                break;
            }
        }
        return prefixStr;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string lcp = solution.longestCommonPrefix(strs);
    cout << lcp << "\n";
    return 0;
}