class TimeMap {
public:
    TimeMap() {
            
    }

    unordered_map<string, vector<pair<string , int>>> mpp;    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        auto& values = mpp[key];
        int l = 0;
        int r = values.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(values[m].second<=timestamp){
                ans = values[m].first;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return ans;      
    }
};
