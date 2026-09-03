#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Complexity Analysis:
//
// Time Complexity: O(m + n).
//
// Let:
//   m = s.length()
//   n = t.length()
//
// Since s and t are passed by value, constructing the function parameters
// can require O(m + n) time when the caller passes lvalue strings.
//
// Building tFreq processes all n characters of t once. Each unordered_map
// operation is O(1) on average, so this takes O(n) time.
//
// The main sliding-window loop processes all m characters of s. Although
// it contains a nested while loop, the left pointer only moves forward.
// Across the entire execution, the left pointer advances at most m times,
// so the total work of the sliding-window phase is O(m).
//
// s.substr(resultL, resultS) constructs the result string and takes
// O(resultS) time, where resultS <= m. Therefore, it costs O(m) in the
// worst case.
//
// Overall:
// O(m + n + m + m) = O(m + n).
//
// Space Complexity: O(m + n).
//
// Passing s and t by value can require O(m + n) additional space for
// their local string objects and character buffers when lvalue arguments
// are passed.
//
// tFreq stores at most 52 distinct character keys because t contains
// only uppercase and lowercase English letters. However, tFreq.reserve(tS)
// reserves bucket capacity proportional to n, so the hash table can use
// O(n) memory.
//
// The string returned by substr can contain up to m characters, requiring
// O(m) space.
//
// Therefore, the total space usage is:
// O(m + n).

class Solution {
  public:
    string minWindow(string s, string t) {
        string result = "";
        const int sS = static_cast<int>(s.size());
        const int tS = static_cast<int>(t.size());
        unordered_map<char, pair<int, int>> tFreq;
        tFreq.reserve(tS);
        int required = tS;
        int resultS = 0;
        int left = 0;
        int resultL = 0;

        for (const char& tChar : t) {
            tFreq[tChar].first++;
        }

        for (int right = 0; right < sS; ++right) {
            // Here auto is pair<const char, pair<int, int>>
            auto it = tFreq.find(s[right]);

            if (it != tFreq.end()) {
                it->second.second++;

                if (it->second.second <= it->second.first) {
                    required--;
                }
            }

            while (required == 0) {
                // Here auto is pair<const char, pair<int, int>>
                auto it1 = tFreq.find(s[left]);

                if (it1 != tFreq.end()) {
                    it1->second.second--;

                    if (it1->second.second < it1->second.first) {
                        const int currentS = right - left + 1;

                        if (currentS < resultS || resultS == 0) {
                            resultS = currentS;
                            resultL = left;
                        }

                        required++;
                    }
                }

                left++;
            }
        }

        result = s.substr(resultL, resultS);
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "ADOBECODEBANC";
    string t = "ABC";

    // Check if the strings are anagrams
    string result = solution.minWindow(s, t);

    // Print the result
    cout << result << "\n";

    return 0;
}