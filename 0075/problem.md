# [75. Sort Colors](https://leetcode.com/problems/sort-colors/description/)

Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them **<a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> ** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Example 2:**

```
Input: nums = [2,0,1]
Output: [0,1,2]
```

**Constraints:**

- <code>n == nums.length</code>
- <code>1 <= n <= 300</code>
- <code>nums[i]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.

**Follow up:** Could you come up with a one-pass algorithm using onlyconstant extra space?
