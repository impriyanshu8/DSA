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
    int lengthLL(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count ++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL ) return NULL;

        int length = lengthLL(head);
        
         if (n == length) {
            ListNode* newHead = head->next;
            delete head; // free memory (optional)
            return newHead;
        }

        ListNode* temp = head;
        for(int i=1; i<(length - n); i++){
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp -> next = temp->next->next;
        delete delNode;
        return head;
        
    }
};