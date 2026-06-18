/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // we try mapping the node in old linked list with the new one
        // so a hash map can be used in this purpose
        unordered_map<Node*, Node*> mpp;
        mpp[NULL] =NULL;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            mpp[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr){
            Node* copy2 = mpp[curr];
            copy2->next = mpp[curr->next];
            copy2->random = mpp[curr->random];
            
            curr = curr->next;
        }
        return mpp[head];      
    }
};
