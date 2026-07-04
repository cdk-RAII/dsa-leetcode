# [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/description/)

Given an array of strings <code>strs</code>, group the <button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_1l_" data-state="closed" class="">anagrams</button> together. You can return the answer in **any order** .

**Example 1:**

<div class="example-block">
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

- There is no string in strs that can be rearranged to form <code>"bat"</code>.
- The strings <code>"nat"</code> and <code>"tan"</code> are anagrams as they can be rearranged to form each other.
- The strings <code>"ate"</code>, <code>"eat"</code>, and <code>"tea"</code> are anagrams as they can be rearranged to form each other.

**Example 2:**

<div class="example-block">
Input: strs = [""]

Output: [[""]]

**Example 3:**

<div class="example-block">
Input: strs = ["a"]

Output: [["a"]]

**Constraints:**

- <code>1 <= strs.length <= 10^4</code>
- <code>0 <= strs[i].length <= 100</code>
- <code>strs[i]</code> consists of lowercase English letters.
