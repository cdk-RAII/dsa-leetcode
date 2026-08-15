# [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

Given two sorted arrays <code>nums1</code> and <code>nums2</code> of size <code>m</code> and <code>n</code> respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be <code>O(log (m+n))</code>.

**Example 1:**

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

**Example 2:**

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

**Constraints:**

- <code>nums1.length == m</code>
- <code>nums2.length == n</code>
- <code>0 <= m <= 1000</code>
- <code>0 <= n <= 1000</code>
- <code>1 <= m + n <= 2000</code>
- <code>-10^6 <= nums1[i], nums2[i] <= 10^6</code>
