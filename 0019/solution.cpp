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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* itHead = head;
        ListNode* itTail = head;
        int ahead = n;
        while (itTail->next != nullptr) {
            if (ahead <= 0) {
                itHead = itHead->next;
            }
            itTail = itTail->next;
            ahead--;
        }
        if (ahead > 0) {
            head = head->next;
        } else {
            itHead->next = itHead->next->next;
        }
        return head;
    }
};

int main() {
    Solution solution;

    const std::vector<int> testCase{1, 2, 3, 4, 5};
    const int n = 5;

    ListNode* head = createList(testCase);
    ListNode* modifiedHead = solution.removeNthFromEnd(head, n);

    printList(modifiedHead);
    deleteList(modifiedHead);

    return 0;
}