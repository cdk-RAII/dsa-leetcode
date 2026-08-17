# [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/)

There is an integer array <code>nums</code> sorted in non-decreasing order (not necessarily with **distinct** values).

Before being passed to your function, <code>nums</code> is **rotated** at an unknown pivot index <code>k</code> (<code>0 <= k < nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (**0-indexed** ). For example, <code>[0,1,2,4,4,4,5,6,6,7]</code> might be rotated at pivot index <code>5</code> and become <code>[4,5,6,6,7,0,1,2,4,4]</code>.

Given the array <code>nums</code> **after** the rotation and an integer <code>target</code>, return <code>true</code> if <code>target</code> is in <code>nums</code>, or <code>false</code> if it is not in <code>nums</code>.

You must decrease the overall operation steps as much as possible.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Constraints:**

- <code>1 <= nums.length <= 5000</code>
- <code>-10^4 <= nums[i] <= 10^4</code>
- <code>nums</code> is guaranteed to be rotated at some pivot.
- <code>-10^4 <= target <= 10^4</code>

**Follow up:** This problem is similar to<a href="/problems/search-in-rotated-sorted-array/description/" target="_blank">Search in Rotated Sorted Array</a>, but<code>nums</code> may contain **duplicates** . Would this affect the runtime complexity? How and why?
