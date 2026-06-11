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
    int count(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head ==nullptr || head->next ==nullptr){
            return nullptr;
        }
        int cnt = count(head);
        int k = cnt- n+1;
        if(k<1||n<1) return head;
        
        if(k==1){
            ListNode* dummy = head->next;
            head->next = nullptr;
            delete head;
            return dummy;
        } 
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int flag = 0;
        while(temp->next){
            flag++;
            prev = temp;
            temp = temp->next;
            if(flag ==k-1){
                ListNode* dum = temp->next;
                temp->next = nullptr;
                prev->next =  dum;
                delete temp;
                return head;
            }
        }         
    }
};
