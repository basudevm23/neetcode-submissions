class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> hashs1(26, 0);

        for(int i=0; i< s1.size(); i++){
            hashs1[s1[i]-'a']++;
        }
        for(int i=0; i< s2.size()-s1.size()+1; i++){
            vector<int> hashs2(26, 0);
            for(int j=i; j< i+s1.size(); j++){
                hashs2[s2[j]-'a']++;
            }
            if(hashs2 == hashs1){
                return true;
            }
        }
        return false;
    }
};
