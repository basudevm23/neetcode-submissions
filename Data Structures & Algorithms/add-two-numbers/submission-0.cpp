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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0, nullptr);
        ListNode* temp = head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry =0;

        while(temp1&&temp2){
            int val1 = temp1->val;
            int val2 = temp2->val;

            int sum = val1 + val2+ carry;
            int digit = sum%10;
            carry = sum/10;

            temp->next = new ListNode(digit, nullptr);
            temp = temp->next;
            temp1 = temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int val = temp1->val;
            int sum = val + carry;
            int digit = sum%10;
            carry = sum/10;
            temp->next = new ListNode(digit, nullptr);
            temp = temp->next;
            temp1 = temp1->next;
        }
        while(temp2){
            int val = temp2->val;
            int sum = val + carry;
            int digit = sum%10;
            carry = sum/10;
            temp->next = new ListNode(digit, nullptr);
            temp = temp->next;
            temp2 = temp2->next;
        }
        while(carry){
            temp->next = new ListNode(carry, nullptr);
            carry = 0;
        }

        return head->next;
    }
};
