#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Complexity Analysis:
// Time Complexity: O(n + n log n) ~ O(n log n), where n is the number of elements in nums.
// buildHeap calls shiftDown on the ~n/2 internal nodes bottom-up; although each call can cost up
// to O(log n), the classical level-by-level analysis shows the total work is O(n) (most nodes sit
// near the bottom, where shiftDown does little), not O(n log n). The extraction loop in sortArray
// then performs n - 1 iterations, each an O(1) swap plus one O(log heapSize) shiftDown from the
// root, costing O(n log n) total. The extraction loop dominates, giving O(n log n) overall.
// Space Complexity: O(log n), not O(1). shiftDown recurses into at most one child per call, so its
// call depth is bounded by the heap's height, O(log heapSize) <= O(log n). C++ does not guarantee
// tail-call optimization, so this recursion consumes real stack space; aside from that, sorting is
// in-place with no other data structures scaling with n.

class Solution {
  public:
    void shiftDown(vector<int>& nums, int heapSize, int parent) {
        int largest = parent;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;

        if (leftChild < heapSize && nums[leftChild] > nums[largest]) {
            largest = leftChild;
        }

        if (rightChild < heapSize && nums[rightChild] > nums[largest]) {
            largest = rightChild;
        }

        if (largest == parent) {
            return;
        }

        swap(nums[parent], nums[largest]);
        shiftDown(nums, heapSize, largest);
    }

    void buildHeap(vector<int>& nums) {
        int heapSize = static_cast<int>(nums.size());
        // A node is a leaf if it has no left child.
        //
        // leftChild = 2 * i + 1
        //
        // A left child exists only when:
        //     leftChild < heapSize
        //
        // Therefore, a left child does not exist when:
        //     leftChild >= heapSize
        //     2 * i + 1 >= heapSize
        //
        // Solving:
        //     2 * i + 1 >= heapSize
        //     2 * i >= heapSize - 1
        //     i >= (heapSize - 1) / 2
        //
        // So, the first leaf starts at index (heapSize - 1) / 2.
        // Therefore, the last non-leaf node (last parent) is:
        //     ((heapSize - 1) / 2) - 1
        //
        // Using integer division in C++, this simplifies to:
        //     heapSize / 2 - 1
        int lastParent = heapSize / 2 - 1;

        // Here auto is "int"
        for (auto i = lastParent; i >= 0; --i) {
            shiftDown(nums, heapSize, i);
        }
    }

    void sortColors(vector<int>& nums) {
        buildHeap(nums);

        int heapSize = static_cast<int>(nums.size());

        while (heapSize > 1) {
            swap(nums[0], nums[heapSize - 1]);
            --heapSize;
            shiftDown(nums, heapSize, 0);
        }
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Test case
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // Sort the array
    solution.sortColors(nums);

    // Print the result
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";

    return 0;
}