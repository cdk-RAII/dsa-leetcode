#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + m + k) ~ O(n), where n is the size of nums, m is the number of unique
// elements in nums, and k is the number of top frequent elements requested. Building the frequency
// map costs O(n); allocating and bucket-erasing the O(n)-sized "temp" array costs O(n); populating
// buckets from the frequency map costs O(m); and collecting the result costs O(m + k) (the outer
// loop scans remaining buckets, the inner loop performs at most k pushes). Since k <= m <= n, this
// simplifies to O(n).
// Space Complexity: O(n + m + k) ~ O(n). The frequency map uses O(m); "temp" (a bucket array sized
// n + 1) uses O(n), which dominates; result uses O(k).

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        result.reserve(k);
        unordered_map<int, int> frequency;
        frequency.reserve(nums.size());

        // Here auto is "int"
        for (const auto& num : nums) {
            frequency[num]++;
        }

        vector<vector<int>> temp(nums.size() + 1);
        // Here auto is "pair<const int, int>"
        for (const auto& [number, freq] : frequency) {
            temp[freq].push_back(number);
        }

        // Here auto is "vector<int>"
        erase_if(temp, [](const auto& v) {
            return v.empty();
        });

        // Here auto is "int"
        for (auto i = static_cast<int>(temp.size()) - 1; i >= 0; --i) {
            size_t j = 0;
            while (k > 0 && j < temp[i].size()) {
                result.push_back(temp[i][j]);
                --k;
                ++j;
            }
        }

        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;

    // Find the top k frequent elements
    vector<int> result = solution.topKFrequent(nums, k);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}