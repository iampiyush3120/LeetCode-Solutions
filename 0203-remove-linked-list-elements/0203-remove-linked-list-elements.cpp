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
    ListNode* removeElements(ListNode* head, int val) {

        // Base case
        if (head == nullptr) {
            return nullptr;
        }

        // Pehle remaining list se elements remove karo
        head->next = removeElements(head->next, val);

        // Agar current node ki value val hai
        if (head->val == val) {
            return head->next;
        }

        return head;
    }
};