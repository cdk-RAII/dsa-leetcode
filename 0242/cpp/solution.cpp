#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> frequency;
        frequency.reserve(s.size());
        for (const char& letter : s) {
            frequency[letter]++;
        }
        for (const char& letter : t) {
            frequency[letter]--;
        }
        // Here auto is "pair<const char, int>"
        for (const auto& [letter, count] : frequency) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    cout << boolalpha << result << "\n";
    return 0;
}