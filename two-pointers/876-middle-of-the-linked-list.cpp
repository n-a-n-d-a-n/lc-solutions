// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr){
            return NULL;
        }
        ListNode* left=head;
        ListNode* right=head;
        while(right!=nullptr&&right->next!=nullptr){
            left=left->next;
            right=right->next->next;
        }
        return left;
    }
};
