#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
        const int s1S = static_cast<int>(s1.size());
        const int s2S = static_cast<int>(s2.size());
        int required = s1S;
        int left = 0;
        unordered_map<char, pair<int, int>> s1Freq;
        s1Freq.reserve(s1S);
        for (const char& s1Char : s1) {
            s1Freq[s1Char].first++;
        }
        for (int right = 0; right < s2S; ++right) {
            auto it = s1Freq.find(s2[right]);
            if (it != s1Freq.end()) {
                it->second.second++;
                if (it->second.second <= it->second.first) {
                    required--;
                }
            }
            while (required == 0) {
                auto it1 = s1Freq.find(s2[left]);
                if (it1 != s1Freq.end()) {
                    it1->second.second--;
                    int currentS = right - left + 1;
                    if (it1->second.second < it1->second.first) {
                        if (currentS == s1S) {
                            return true;
                        } else {
                            required++;
                        }
                    }
                }
                left++;
            }
        }
        return false;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s1 = "adc";
    string s2 = "dcda";

    // Check if the strings are anagrams
    bool result = solution.checkInclusion(s1, s2);

    // Print the result
    cout << boolalpha << result << "\n";

    return 0;
}