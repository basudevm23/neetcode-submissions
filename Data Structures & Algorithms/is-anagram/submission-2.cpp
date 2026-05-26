class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,char> mpp1;
        map<char, char> mpp2;
        for(int i=0; i<s.size(); i++){
            if(mpp1.find(s[i])==mpp1.end()){
                mpp1[s[i]]=1;
            }
            else{
                mpp1[s[i]]++;
            }      
        }
        for(int i=0; i<t.size(); i++){
            if(mpp2.find(t[i])==mpp2.end()){
                mpp2[t[i]]=1;
            }
            else{
                mpp2[t[i]]++;
            }
        }
        return mpp1==mpp2;
    }
};
