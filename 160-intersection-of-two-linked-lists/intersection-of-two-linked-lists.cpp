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
        ListNode* temp = headA;
        ListNode* tempp = headB;
        if(temp == tempp) return temp;
        while(temp!= NULL){
            while( tempp != NULL){
            if(tempp == temp) return temp;
            tempp = tempp->next;
            }
        tempp = headB ;
        temp = temp->next;
        }
        return NULL;
    }
};