// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr){
            return NULL;
        }
        while(head!=nullptr&&head->val==val){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};
