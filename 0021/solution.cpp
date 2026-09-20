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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* tail = head;

        while (list1 != nullptr && list2 != nullptr) {
            ListNode* current = nullptr;

            if (list1->val <= list2->val) {
                current = list1;
                list1 = list1->next;
            } else {
                current = list2;
                list2 = list2->next;
            }

            if (head == nullptr) {
                head = current;
                tail = current;
            } else {
                tail->next = current;
                tail = tail->next;
            }
        }

        tail->next = (list1 != nullptr) ? list1 : list2;

        return head;
    }
};

int main() {
    Solution solution;

    const std::vector<int> list1Vector{1, 2, 4};
    const std::vector<int> list2Vector{1, 3, 4};

    ListNode* list1 = createList(list1Vector);
    ListNode* list2 = createList(list2Vector);
    ListNode* sortedMergedList = solution.mergeTwoLists(list1, list2);

    printList(sortedMergedList);
    deleteList(sortedMergedList);
    deleteList(list2);
    deleteList(list1);

    return 0;
}