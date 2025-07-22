#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    
    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class containing the logic
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to simplify handling of head
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        // Loop continues until both lists and carry are exhausted
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // Add value from l1 if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2 if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry and the current digit
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        // Return the result list starting after dummy node
        return dummy->next;
    }
};

// Helper function to create a linked list from a number (in reverse order)
ListNode* createList(int num) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    // Special case for number 0
    if (num == 0) return new ListNode(0);

    while (num > 0) {
        int digit = num % 10;
        if (head == nullptr) {
            head = tail = new ListNode(digit);
        } else {
            tail->next = new ListNode(digit);
            tail = tail->next;
        }
        num /= 10;
    }

    return head;
}

// to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the logic
int main() {
    
    ListNode* l1 = createList(342);
    ListNode* l2 = createList(465);

    // Solution object
    Solution solution;

    // Call the method
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Resultant Linked List: ";
    printList(result);

    return 0;
}
