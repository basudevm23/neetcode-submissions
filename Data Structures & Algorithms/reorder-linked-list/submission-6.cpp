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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow->next;
        slow->next = nullptr;
        ListNode* dummy = nullptr;

        while(prev){
            ListNode* front = prev->next;
            prev->next = dummy;
            dummy = prev;
            prev = front;
        }
        ListNode* straight= head;
        ListNode* reverse = dummy;

        while(reverse){
            ListNode* temps = straight->next;
            ListNode* tempr = reverse->next;
            
            straight->next = reverse;
            reverse->next = temps;

            straight = temps;
            reverse = tempr;           
        }
    }
};
