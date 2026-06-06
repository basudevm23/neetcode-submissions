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
        int l = 0;
        int r = mpp[key].size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(mpp[key][m].second<=timestamp){
                ans = mpp[key][m].first;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return ans;      
    }
};
