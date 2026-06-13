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
    ListNode* shifter(ListNode* head, int k){
        while(head&&k>0){
            head = head->next;
            k--;
        }    
        return head;            
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroup = dummy;
        while(true){
            ListNode* kth = shifter(prevGroup, k);
            if(kth==nullptr){
                break;
            }
            ListNode* groupNext = kth->next;
            ListNode* prev = kth->next;
            ListNode* curr = prevGroup->next;
            while(curr!=groupNext){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;                
            }
            ListNode* temp =prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }  
        return dummy->next;      
    }
};
