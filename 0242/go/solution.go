package main

import "fmt"

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	frequency := make(map[rune]int, len(s))

	for _, letter := range s {
		frequency[letter]++
	}

	for _, letter := range t {
		frequency[letter]--
	}

	for _, count := range frequency {
		if count != 0 {
			return false
		}
	}

	return true
}

func main() {
	// Test case for checking if two strings are anagrams
	s := "anagram"
	t := "nagaram"

	// Call the isAnagram function with the test case strings
	result := isAnagram(s, t)

	fmt.Println(result)
}
