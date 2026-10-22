package main

import "fmt"

func twoSum(nums []int, target int) []int {
	diff := make(map[int]int, len(nums))

	for idx, num := range nums {
		if i, ok := diff[num]; ok {
			return []int{i, idx}
		}

		diff[target-num] = idx
	}

	return []int{}
}

func main() {
	// Test case for the twoSum function
	nums := []int{2, 4, 11, 15}
	target := 9

	// Call the twoSum function with the test case
	result := twoSum(nums, target)

	// Print the result of the twoSum function
	fmt.Println(result)
}
