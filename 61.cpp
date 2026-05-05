// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0||!head->next){
            return head;
        }
        ListNode* tail=head;
        int n=1;
        while(tail->next){
            tail=tail->next;
            n++;
        }
        k=k%n;
        if(k==0){
            return head;
        }
        tail->next=head;
        ListNode* newTail=head;
        for(int i=0;i<n-k-1;i++){
            newTail=newTail->next;
        }
        ListNode* newHead=newTail->next;
        newTail->next=nullptr;
        return newHead;
    }
};
