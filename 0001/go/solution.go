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
	nums := []int{2, 4, 11, 15}
	target := 9
	result := twoSum(nums, target)
	fmt.Println(result)
}
