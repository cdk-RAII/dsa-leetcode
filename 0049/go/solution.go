package main

import (
	"fmt"
	"slices"
)

func sortString(s string) string {
	runes := []rune(s)
	slices.Sort(runes)
	return string(runes)
}

func groupAnagrams(strs []string) [][]string {
	anagramsMap := make(map[string][]string, len(strs))
	for _, str := range strs {
		sortedStr := sortString(str)
		anagramsMap[sortedStr] = append(anagramsMap[sortedStr], str)
	}
	result := make([][]string, 0, len(anagramsMap))
	for _, anagramsGroup := range anagramsMap {
		result = append(result, anagramsGroup)
	}
	return result
}

func main() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	result := groupAnagrams(strs)
	fmt.Println(result)
}
