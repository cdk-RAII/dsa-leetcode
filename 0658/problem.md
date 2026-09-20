# [658. Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/description/)

Given a **sorted** integer array <code>arr</code>, two integers <code>k</code> and <code>x</code>, return the <code>k</code> closest integers to <code>x</code> in the array. The result should also be sorted in ascending order.

An integer <code>a</code> is closer to <code>x</code> than an integer <code>b</code> if:

- <code>|a - x| < |b - x|</code>, or
- <code>|a - x| == |b - x|</code> and <code>a < b</code>

**Example 1:**

<div class="example-block">
Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

**Example 2:**

<div class="example-block">
Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

**Constraints:**

- <code>1 <= k <= arr.length</code>
- <code>1 <= arr.length <= 10^4</code>
- <code>arr</code> is sorted in **ascending** order.
- <code>-10^4 <= arr[i], x <= 10^4</code>
