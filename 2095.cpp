// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.
// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return NULL;
        }
        ListNode* left=head;
        ListNode* right=head;
        ListNode* prev=nullptr;
        while(right!=nullptr&&right->next!=nullptr){
            prev=left;
            left=left->next;
            right=right->next->next;
        }
        prev->next=left->next;
        delete left;
        return head;
    }
};
