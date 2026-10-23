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
	nums := []int{1, 2, 3, 1}
	contains := containsDuplicate(nums)
	fmt.Println(contains)
}
