class CountSquares {
    vector<pair<int, int>> store;
    map <pair<int,int>, int> mpp;
public:
    CountSquares() {
    
    }

    void add(vector<int> point) {
        int px = point[0];
        int py = point[1];
        store.push_back({px, py});
        mpp[{px,py}]++;              
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res=  0;
        for(int i=0; i<store.size(); i++){
            int x = store[i].first;
            int y = store[i].second;
            if(abs(px - x)!=abs(py - y) || px==x || py == y){
                continue;
            }
            res += mpp[{px, y}]*mpp[{x, py}];
        }
        return res;
    }
};
