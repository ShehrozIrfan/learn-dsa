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
    ListNode* deleteDuplicates(ListNode* head) {
        // base case
        if(!head || !head->next){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head;
        ListNode *prev = dummy;

        while(current!=nullptr && current->next!=nullptr){
            if(current->val == current->next->val){
                int match = current->val;
                while(current!=nullptr && current->val == match){
                    current = current->next;
                }
                prev->next = current;

            }
            else{
                prev = current;
                current = current->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};