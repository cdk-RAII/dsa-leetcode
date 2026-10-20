package main

import (
	"fmt"
)

func getConcatenation(nums []int) []int {
	n := len(nums)
	ans := make([]int, 2*n)
	copy(ans, nums)
	copy(ans[n:], nums)
	return ans
}

func main() {
	// Test case
	nums := []int{1, 2, 1}

	// Get the concatenated result
	result := getConcatenation(nums)

	// Print the result
	fmt.Println(result)
}
