# [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/description/)

Given an integer array <code>nums</code> and an integer <code>k</code>, return <code>true</code> if there are two **distinct indices** <code>i</code> and <code>j</code> in the array such that <code>nums[i] == nums[j]</code> and <code>abs(i - j) <= k</code>.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

**Constraints:**

- <code>1 <= nums.length <= 10^5</code>
- <code>-10^9 <= nums[i] <= 10^9</code>
- <code>0 <= k <= 10^5</code>
