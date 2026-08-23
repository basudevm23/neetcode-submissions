class Solution {
public:
    bool comp(string word1, string word2, unordered_map<char, int> mpp){
        int i =0;
        int j = 0;

        int n1 = word1.length();
        int n2 = word2.length();

        while(i<n1 && j<n2){
            if(mpp[word1[i]] < mpp[word2[i]]){
                return true; 
            }
            if(mpp[word1[i]] > mpp[word2[j]]){
                return false;
            }
            i++;
            j++;
        }

        return n1 <= n2;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        for(int i =0; i<order.size(); i++){
            mpp[order[i]] = i;
        }
        for(int i = 0; i<words.size()-1; i++){
            if(comp(words[i], words[i+1], mpp) == false) return false;
        }
        return true;
    }
};