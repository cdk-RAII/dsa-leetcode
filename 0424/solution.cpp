#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int characterReplacement(string s, int k) {
        int result = 0;
        int maxFreqCharS = 0;
        int sS = static_cast<int>(s.size());
        int left = 0;
        unordered_map<char, int> windowFreq;
        windowFreq.reserve(26);
        for (int right = 0; right < sS; ++right) {
            windowFreq[s[right]]++;
            maxFreqCharS = max(windowFreq[s[right]], maxFreqCharS);
            while (right - left + 1 - maxFreqCharS > k) {
                windowFreq[s[left]]--;
                left++;
            }
            result = max(right - left + 1, result);
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "AABABBA";
    int k = 1;

    // Calculate the length of the longest substring with at most k replacements
    int result = solution.characterReplacement(s, k);

    // Print the result
    cout << result << "\n";

    return 0;
}