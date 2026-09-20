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

ListNode* findCycleStart(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Phase 1: Detect whether a cycle exists.
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // No cycle.
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    // Phase 2: Find the beginning of the cycle.
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Create a linked list and optionally make it circular.
ListNode* createCircularList(const std::vector<int>& values, int pos) {
    if (values.empty()) {
        return nullptr;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleStart = nullptr;

    for (size_t i = 0; i < values.size(); ++i) {
        ListNode* newNode = new ListNode(values[i]);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        // Remember the node at 'pos'.
        if (static_cast<int>(i) == pos) {
            cycleStart = newNode;
        }
    }

    // Create the cycle only when pos is valid.
    if (pos >= 0 && pos < static_cast<int>(values.size())) {
        tail->next = cycleStart;
    }

    return head;
}

void printCircularList(const ListNode* head) {
    cout << "[";

    if (head == nullptr) {
        cout << "]\n";
        return;
    }

    const ListNode* cycleStart = findCycleStart(const_cast<ListNode*>(head));

    // ------------------------------------------------------------
    // Case 1: No cycle
    // ------------------------------------------------------------
    if (cycleStart == nullptr) {
        const ListNode* current = head;

        while (current != nullptr) {
            cout << current->val;

            if (current->next != nullptr) {
                cout << ", ";
            }

            current = current->next;
        }

        cout << "]\n";
        return;
    }

    // ------------------------------------------------------------
    // Case 2: Cycle exists
    // ------------------------------------------------------------

    // Print the nodes before the cycle.
    const ListNode* current = head;

    while (current != cycleStart) {
        cout << current->val << ", ";
        current = current->next;
    }

    // Print the cycle once.
    const ListNode* cycleNode = cycleStart;

    while (true) {
        cout << cycleNode->val;
        cycleNode = cycleNode->next;

        if (cycleNode == cycleStart) {
            break;
        }

        cout << ", ";
    }

    // Print the cycle a second time.
    cycleNode = cycleStart;

    cout << ", ";

    while (true) {
        cout << cycleNode->val;
        cycleNode = cycleNode->next;

        if (cycleNode == cycleStart) {
            break;
        }

        cout << ", ";
    }

    cout << ", ...]\n";
}

// Delete both normal and cyclic lists safely.
void deleteCircularList(ListNode* head) {
    if (head == nullptr) {
        return;
    }

    ListNode* cycleStart = findCycleStart(head);

    // If there is a cycle, break it first.
    if (cycleStart != nullptr) {
        ListNode* cycleTail = cycleStart;

        while (cycleTail->next != cycleStart) {
            cycleTail = cycleTail->next;
        }

        cycleTail->next = nullptr;
    }

    // Now the list is a normal linear list.
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

class Solution {
  public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    const vector<int> circularList{1, 2, 3, 4, 5};
    const int pos = 2;

    ListNode* head = createCircularList(circularList, pos);
    printCircularList(head);

    bool hasCycle = solution.hasCycle(head);

    cout << boolalpha << hasCycle;
    deleteCircularList(head);

    return 0;
}