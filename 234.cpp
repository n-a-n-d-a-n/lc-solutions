// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        vector<int> elements;
        ListNode* current=head;
        while(current!=nullptr){
            elements.push_back(current->val);
            current=current->next;
        }
        int left=0;
        int right=elements.size()-1;
        while(left<right){
            if(elements[left]!=elements[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
