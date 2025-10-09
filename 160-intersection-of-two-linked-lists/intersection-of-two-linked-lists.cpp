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
        unordered_set< ListNode* > str;
        while(headA != NULL){
            str.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
             if (str.find(headB) != str.end()) return headB;
             headB = headB -> next;
        }
        return NULL;
    }
};