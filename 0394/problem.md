# [394. Decode String](https://leetcode.com/problems/decode-string/description/)

Given an encoded string, return its decoded string.

The encoding rule is: <code>k[encoded_string]</code>, where the <code>encoded_string</code> inside the square brackets is being repeated exactly <code>k</code> times. Note that <code>k</code> is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, <code>k</code>. For example, there will not be input like <code>3a</code> or <code>2[4]</code>.

The test cases are generated so that the length of the output will never exceed <code>10^5</code>.

**Example 1:**

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
```

**Example 2:**

```
Input: s = "3[a2[c]]"
Output: "accaccacc"
```

**Example 3:**

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
```

**Constraints:**

- <code>1 <= s.length <= 30</code>
- <code>s</code> consists of lowercase English letters, digits, and square brackets <code>'[]'</code>.
- <code>s</code> is guaranteed to be **a valid** input.
- All the integers in <code>s</code> are in the range <code>[1, 300]</code>.
