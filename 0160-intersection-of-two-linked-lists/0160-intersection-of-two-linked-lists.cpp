/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>st;
        ListNode *temp = headB;

        while(temp!= NULL){
            st.insert(temp);
            temp = temp -> next;
        }
        temp = headA;
    while(temp!= NULL){
        if(st.contains (temp)){
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
        
    }
};