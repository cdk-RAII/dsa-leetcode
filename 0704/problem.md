# [704. Binary Search](https://leetcode.com/problems/binary-search/description/)

Given an array of integers <code>nums</code> which is sorted in ascending order, and an integer <code>target</code>, write a function to search <code>target</code> in <code>nums</code>. If <code>target</code> exists, then return its index. Otherwise, return <code>-1</code>.

You must write an algorithm with <code>O(log n)</code> runtime complexity.

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Constraints:**

- <code>1 <= nums.length <= 10^4</code>
- <code>-10^4 < nums[i], target < 10^4</code>
- All the integers in <code>nums</code> are **unique** .
- <code>nums</code> is sorted in ascending order.
