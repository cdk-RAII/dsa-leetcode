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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* tail = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum %= 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
        }

        return head->next;
    }
};

int main() {
    Solution solution;

    const vector<int> list1Vector{2, 4, 3};
    const vector<int> list2Vector{5, 6, 4};

    ListNode* list1 = createList(list1Vector);
    ListNode* list2 = createList(list2Vector);
    ListNode* addition = solution.addTwoNumbers(list1, list2);

    printList(addition);
    deleteList(addition);
    deleteList(list2);
    deleteList(list1);

    return 0;
}