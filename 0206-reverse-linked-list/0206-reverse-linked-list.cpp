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
    ListNode* reverseList(ListNode* head) {

        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Rest of the list reverse karo
        ListNode* newHead = reverseList(head->next);

        // Current node ko reverse direction mein connect karo
        head->next->next = head;

        // Old direction remove karo
        head->next = nullptr;

        return newHead;
    }
};