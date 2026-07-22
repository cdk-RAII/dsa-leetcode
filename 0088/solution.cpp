#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(m + n), where m is the number of valid elements in nums1 and n is the number
// of elements in nums2. The algorithm uses three pointers starting from the ends of the arrays.
// During each iteration of the loop, either n1Ptr or n2Ptr moves one position to the left, and
// tempPtr also moves one position to the left. Each element from nums1 is moved at most once, and
// each element from nums2 is copied into nums1 at most once. Therefore, the total number of pointer
// movements is at most m + n, giving O(m + n) time.
// Space Complexity: O(1), where m is the number of valid elements in nums1 and n is the number of
// elements in nums2. The algorithm performs the merge in place using only three integer variables
// (n1Ptr, n2Ptr, and tempPtr). No additional data structures whose size depends on m or n are
// allocated.

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1Ptr = m - 1;
        int n2Ptr = n - 1;
        int tempPtr = m + n - 1;
        while (n > 0) {
            if (n1Ptr >= 0 && nums1[n1Ptr] >= nums2[n2Ptr]) {
                nums1[tempPtr] = nums1[n1Ptr];
                tempPtr--;
                n1Ptr--;
            } else {
                nums1[tempPtr] = nums2[n2Ptr];
                tempPtr--;
                n2Ptr--;
                n--;
            }
        }
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Merge the arrays
    solution.merge(nums1, m, nums2, n);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < nums1.size(); ++i) {
        cout << nums1[i];
        if (i < nums1.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}