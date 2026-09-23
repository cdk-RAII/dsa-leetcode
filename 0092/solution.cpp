#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (const int value : values) {
        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void printList(const ListNode* head) {
    std::cout << "[";

    for (const ListNode* current = head; current != nullptr; current = current->next) {
        std::cout << current->val;

        if (current->next != nullptr) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {
            return head;
        }

        ListNode* itHead = new ListNode(0, head);
        ListNode* itTail = itHead;
        int i = 0;

        while (i < left - 1) {
            itTail = itTail->next;
            i++;
        }

        ListNode* reverseTail = itTail->next;
        ListNode* prevN = nullptr;
        ListNode* currN = reverseTail;

        while (i < right) {
            ListNode* nextN = currN->next;
            currN->next = prevN;
            prevN = currN;
            currN = nextN;
            i++;
        }

        itTail->next = prevN;
        reverseTail->next = currN;
        ListNode* newHead = itHead->next;

        delete itHead;
        return newHead;
    }
};

int main() {
    Solution solution;

    const std::vector<int> testCase{1, 2, 3, 4, 5};
    const int left = 2;
    const int right = 4;

    ListNode* head = createList(testCase);
    ListNode* modifiedHead = solution.reverseBetween(head, left, right);

    printList(modifiedHead);
    deleteList(modifiedHead);

    return 0;
}