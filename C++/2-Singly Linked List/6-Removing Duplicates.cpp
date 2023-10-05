#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

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



int main() {
    // Create a sample linked list with duplicates
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Print the original linked list
    std::cout << "Original Linked List: ";
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Call the deleteDuplicates function to remove duplicates
    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);

    // Print the modified linked list without duplicates
    std::cout << "Modified Linked List: ";
    current = newHead;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    current = newHead;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
