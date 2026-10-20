package main

import "fmt"

func containsDuplicate(nums []int) bool {
	seen := make(map[int]bool, len(nums))

	for _, num := range nums {
		if seen[num] {
			return true
		}

		seen[num] = true
	}

	return false
}

func main() {
	// Test case: check for duplicates in the array
	nums := []int{1, 2, 3, 1}

	// Check for duplicates in the array
	contains := containsDuplicate(nums)

	fmt.Println(contains)
}
