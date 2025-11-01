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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>frq(nums.begin(), nums.end());
        while(head && frq.count(head->val)){
            head = head->next;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!=NULL){
            if(frq.count(temp->val) ){
                temp = temp->next;
                prev->next = temp;
            }
            else{
                prev = temp;
                temp = temp->next; 
            }

        }
        return head;
    }
};