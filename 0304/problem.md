# [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/description/)

Given a 2D matrix <code>matrix</code>, handle multiple queries of the following type:

- Calculate the **sum** of the elements of <code>matrix</code> inside the rectangle defined by its **upper left corner** <code>(row1, col1)</code> and **lower right corner** <code>(row2, col2)</code>.

Implement the <code>NumMatrix</code> class:

- <code>NumMatrix(int[][] matrix)</code> Initializes the object with the integer matrix <code>matrix</code>.
- <code>int sumRegion(int row1, int col1, int row2, int col2)</code> Returns the **sum** of the elements of <code>matrix</code> inside the rectangle defined by its **upper left corner** <code>(row1, col1)</code> and **lower right corner** <code>(row2, col2)</code>.

You must design an algorithm where <code>sumRegion</code> works on <code>O(1)</code> time complexity.

**Example 1:**
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/sum-grid.jpg" style="width: 415px; height: 415px;">

```
Input

["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output

[null, 8, 11, 12]

Explanation

NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
```

**Constraints:**

- <code>m == matrix.length</code>
- <code>n == matrix[i].length</code>
- <code>1 <= m, n <= 200</code>
- <code>-10^4 <= matrix[i][j] <= 10^4</code>
- <code>0 <= row1 <= row2 < m</code>
- <code>0 <= col1 <= col2 < n</code>
- At most <code>10^4</code> calls will be made to <code>sumRegion</code>.
