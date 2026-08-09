#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + m) ~ O(m), where n is the length of the input string s and m is the length
// of the decoded output string. The for loop processes all n characters of the encoded string,
// requiring O(n) time. Whenever a closing bracket is encountered, the algorithm repeats the
// currently decoded substring according to its frequency and appends it to tempS. Across all
// decoding operations, the total number of characters that must ultimately be produced is m,
// so the total string construction and append work is O(m). Therefore, the total time complexity
// is O(n + m) ~ O(m), where m can be as large as 10^5 according to the problem constraints.
// Space Complexity: O(n + m) ~ O(m), where n is the length of the input string s and m is the
// length of the decoded output string. The decoded string and intermediate strings can together
// require O(m) space. The codeFreq vector stores the nested repetition levels and their partially
// decoded strings; in the worst case, this can also require O(m) total space. numString requires
// O(n) space in the worst case for the digits of a repetition count. Therefore, the total space
// complexity is O(n + m) ~ O(m).

class Solution {
  public:
    string decodeString(string s) {
        // Here vector codeFreq is used as stack to store the frequency and the corresponding
        // decoded string.
        vector<pair<int, string>> codeFreq;
        string decoded;
        string numString;

        for (const char c : s) {
            if (isalpha(static_cast<unsigned char>(c)) && codeFreq.empty()) {
                decoded.push_back(c);
            } else if (isdigit(static_cast<unsigned char>(c))) {
                numString.push_back(c);
            } else if (c == '[') {
                codeFreq.emplace_back(stoi(numString), "");
                numString.clear();
            } else if (isalpha(static_cast<unsigned char>(c))) {
                codeFreq[codeFreq.size() - 1].second.push_back(c);
            } else {
                int tempI = codeFreq[codeFreq.size() - 1].first;
                string tempS;

                while (tempI-- != 0) {
                    tempS.append(codeFreq[codeFreq.size() - 1].second);
                }

                codeFreq.pop_back();

                if (codeFreq.empty()) {
                    decoded.append(tempS);
                } else {
                    codeFreq[codeFreq.size() - 1].second.append(tempS);
                }
            }
        }

        return decoded;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    string s = "2[abc]3[cd]ef";

    // Decode the string
    string decodedString = solution.decodeString(s);

    // Print the result
    cout << decodedString << "\n";

    return 0;
}