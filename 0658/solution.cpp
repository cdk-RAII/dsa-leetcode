#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        result.reserve(k);
        int arrS = static_cast<int>(arr.size());
        int left = 0;
        int right = arrS - 1;
        int closestToX = 0;
        while (right >= left) {
            int searchS = right - left;
            int mid = left + searchS / 2;
            if (arr[mid] < x) {
                left = mid + 1;
            } else if (arr[mid] >= x) {
                right = mid - 1;
            }
        }
        int start = min(left, right);
        int end = max(left, right);
        if (start < 0) {
            closestToX = 0;
        } else if (end >= arrS) {
            closestToX = arrS - 1;
        } else if (abs(arr[start] - x) <= abs(arr[end] - x)) {
            closestToX = start;
        } else {
            closestToX = end;
        }
        start = closestToX;
        end = closestToX;
        while (end - start + 1 < k) {
            if (start == 0) {
                end++;
            } else if (end == arrS - 1) {
                start--;
            } else if (abs(arr[start - 1] - x) <= abs(arr[end + 1] - x)) {
                start--;
            } else {
                end++;
            }
        }
        int i = 0;
        while (i < k) {
            result.push_back(arr[start]);
            start++;
            i++;
        }
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;

    // Find the k closest elements to x
    vector<int> result = solution.findClosestElements(nums, k, x);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}