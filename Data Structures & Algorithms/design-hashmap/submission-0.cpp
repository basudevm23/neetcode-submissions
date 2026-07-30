class MyHashMap {
    vector<pair<int, int>> hashhash;
public:
    MyHashMap() {
    }

    void put(int key, int value) {
        int flag = 0;
        for(auto &it: hashhash){
            if(it.first == key){
                it.second = value;
                flag = 1;
            }
        } 
        if(flag == 0){
            hashhash.push_back({key, value});
        }       
    }
    
    int get(int key) {
        for(auto &it: hashhash){
            if(it.first == key){
                return it.second;
            }
        } 
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i<hashhash.size(); i++){
            if(hashhash[i].first==key){
                hashhash.erase(hashhash.begin() + i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */