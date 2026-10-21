/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Helper function linked list ko reverse karne ke liye (Aapka hi reverse logic)
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL, *c = head;
        while (c != NULL) {
            ListNode* n = c->next; // next node ko save kiya
            c->next = p;           // link ko reverse kiya
            p = c;                 // p ko aage badhaya
            c = n;                 // c ko aage badhaya
        }
        return p; // New head return kiya
    }

    bool isPalindrome(ListNode* head) {
        // Base case: Agar list khali hai ya single element hai
        if (head == NULL || head->next == NULL) return true;

        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        slow->next = reverseList(slow->next);

        // Step 3: Compare the first half and the reversed second half
        ListNode *a = head;
        ListNode *b = slow->next;
        while (b != NULL) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }

        return true;
    }
};
