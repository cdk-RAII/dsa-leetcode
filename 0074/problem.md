# [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

You are given an <code>m x n</code> integer matrix <code>matrix</code> with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer <code>target</code>, return <code>true</code> if <code>target</code> is in <code>matrix</code> or <code>false</code> otherwise.

You must write a solution in <code>O(log(m \* n))</code> time complexity.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat.jpg" style="width: 322px; height: 242px;">

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg" style="width: 322px; height: 242px;">

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

- <code>m == matrix.length</code>
- <code>n == matrix[i].length</code>
- <code>1 <= m, n <= 100</code>
- <code>-10^4 <= matrix[i][j], target <= 10^4</code>
