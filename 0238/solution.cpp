#include <iostream>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n^2), where n is nums.size(). For each of the n indices i, leftMultiply
// recurses from i - 1 down to -1 (O(i) calls) and rightMultiply recurses from i + 1 up to n
// (O(n - i) calls), so each outer iteration costs O(i) + O(n - i) = O(n). Summing O(n) work over
// n iterations gives O(n^2) - this brute-force approach recomputes both products from scratch at
// every index instead of reusing previously computed partial products.
// Space Complexity: O(n). leftMultiply and rightMultiply are real recursive calls (C++ does not
// guarantee tail-call optimization), and each can recurse to a depth of O(n) within a single outer
// iteration (left and right calls are sequential, not nested, so their stack usage doesn't add -
// the peak per iteration is O(max(i, n - i)) <= O(n)). Plus O(n) for the result vector.

// class Solution {
//   public:
//     int rightMultiply(vector<int>& nums, int from) {
//         if (from > nums.size() - 1) {
//             return 1;
//         }
//         return nums[from] * rightMultiply(nums, from + 1);
//     }
//     int leftMultiply(vector<int>& nums, int from) {
//         if (from < 0) {
//             return 1;
//         }
//         return nums[from] * leftMultiply(nums, from - 1);
//     }
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> result;
//         for (int i = 0; i < nums.size(); ++i) {
//             int product = leftMultiply(nums, i - 1) * rightMultiply(nums, i + 1);
//             result.push_back(product);
//         }
//         return result;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is nums.size(). The first loop fills rightProduct in
// a single backward pass (O(n)); the second loop fills leftProduct and combines it with
// rightProduct into product in a single forward pass (O(n)). Two sequential O(n) passes sum to
// O(n) - a major improvement over Solution 1's O(n^2), achieved by caching partial products
// instead of recomputing them.
// Space Complexity: O(n + n + n) ~ O(n). Three vectors of size n (leftProduct, rightProduct, and
// the output product) are allocated; each is O(n), so the total remains O(n).

// class Solution {
//   public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int numsSize = static_cast<int>(nums.size());
//         vector<int> product(numsSize);
//         vector<int> leftProduct(numsSize);
//         vector<int> rightProduct(numsSize);
//         for (int i = numsSize - 1; i >= 0; --i) {
//             if (i == numsSize - 1) {
//                 rightProduct[i] = 1;
//             } else {
//                 rightProduct[i] = nums[i + 1] * rightProduct[i + 1];
//             }
//         }
//         for (int i = 0; i < numsSize; ++i) {
//             if (i == 0) {
//                 leftProduct[i] = 1;
//             } else {
//                 leftProduct[i] = nums[i - 1] * leftProduct[i - 1];
//             }
//             product[i] = leftProduct[i] * rightProduct[i];
//         }
//         return product;
//     }
// };

// Complexity Analysis:
// Time Complexity: O(n + n) ~ O(n), where n is nums.size(). The first loop fills product with
// right-side products in a single backward pass (O(n)); the second loop multiplies in the
// running left product leftTempProduct in a single forward pass (O(n)). Total: O(n), same order
// as Solution 2.
// Space Complexity: O(1) auxiliary (excluding the required output array), where n is nums.size().
// Only leftTempProduct is extra scalar storage - product itself is reused both as the working
// buffer and the returned result, eliminating the separate leftProduct/rightProduct arrays that
// Solution 2 needed. (If the output array is counted, this is O(n), same as the other two, but
// this is the solution to prefer since it needs no extra O(n) buffers beyond the answer itself.)

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = static_cast<int>(nums.size());
        vector<int> product(numsSize);
        int leftTempProduct = 1;
        for (int i = numsSize - 1; i >= 0; --i) {
            if (i == numsSize - 1) {
                product[i] = 1;
            } else {
                product[i] = nums[i + 1] * product[i + 1];
            }
        }
        for (int i = 1; i < numsSize; ++i) {
            leftTempProduct *= nums[i - 1];
            product[i] *= leftTempProduct;
        }
        return product;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 4};

    // Find the product except self
    vector<int> result = solution.productExceptSelf(nums);

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