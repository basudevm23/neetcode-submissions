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

    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0) return nullptr;
        
        while(lists.size()>1){
            vector<ListNode*> mergedlists;
            for(int i=0; i<lists.size(); i = i+2){
                ListNode* l1 = lists[i];
                ListNode* l2 =nullptr;
                if((i+1)<lists.size()){
                    l2 = lists[i+1];
                }
                mergedlists.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedlists;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2==nullptr && list1!=nullptr){
            return list1;
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while(temp1 && temp2){
            if(temp1->val >= temp2->val){
                if(head == nullptr){
                    head = temp2;
                    prev= temp2;
                }
                else{
                    prev->next = temp2;
                    prev = temp2;
                }
                temp2 = temp2->next;                                
            }
            else{
                if(head == nullptr){
                    head = temp1;
                    prev = temp1;
                }
                else{
                    prev->next = temp1;
                    prev = temp1;
                }
                temp1 = temp1->next;
            }
        } 
        if(temp2!=nullptr){
            prev->next = temp2;
        }
        else if(temp1 != nullptr){
            prev->next = temp1;
        }
        return head;       
    }
};
