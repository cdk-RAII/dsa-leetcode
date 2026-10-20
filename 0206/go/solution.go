package main

import (
	"os"
	"strconv"
)

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func createList(values []int) *ListNode {
	if len(values) == 0 {
		return nil
	}

	nodes := make([]ListNode, len(values))
	for i, v := range values {
		nodes[i].Val = v
		if i > 0 {
			nodes[i-1].Next = &nodes[i]
		}
	}

	return &nodes[0]
}

func printList(head *ListNode) {
	buf := make([]byte, 0, 64)
	buf = append(buf, '[')

	for curr := head; curr != nil; curr = curr.Next {
		buf = strconv.AppendInt(buf, int64(curr.Val), 10)

		if curr.Next != nil {
			buf = append(buf, ',', ' ')
		}
	}

	buf = append(buf, ']', '\n')
	os.Stdout.Write(buf)
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	curr := head

	for curr != nil {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}

	return prev
}

func main() {
	testCase := []int{1, 2, 3, 4, 5}

	head := createList(testCase)
	reversedHead := reverseList(head)

	printList(reversedHead)
}
