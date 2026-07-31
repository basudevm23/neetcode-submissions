class Node{
public:
    int key;
    Node* next;
    Node(int key){
        this->key = key;
        next = nullptr;
    }
};
class MyHashSet {
private:
    vector<Node*> table;
public:
    MyHashSet() {
        table.resize(10000);

        for(int i=0; i<table.size(); i++){
            table[i] = new Node(0);
        }
        
    }
    void add(int key) {

        Node* curr = table[key%table.size()];

        while(curr->next!=nullptr){
            if(curr->next->key == key){
                return;
            }

            curr = curr->next;
            
        }
        curr->next = new Node(key);

    }
    
    void remove(int key) {
        Node* curr = table[key%table.size()];

        while(curr->next!=nullptr){
            if(curr->next->key == key){
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        Node* curr = table[key% table.size()];

        while(curr->next!=nullptr){
            if(curr->next->key == key){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */