package main

import "fmt"

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	prefixStr := strs[0]
	for i := 1; i < len(strs); i++ {
		j := 0
		for j < len(prefixStr) && j < len(strs[i]) && prefixStr[j] == strs[i][j] {
			j++
		}
		prefixStr = prefixStr[:j]
		if prefixStr == "" {
			break
		}
	}
	return prefixStr
}

func main() {
	strs := []string{"flower", "flow", "flight"}
	result := longestCommonPrefix(strs)
	fmt.Println(result)
}
