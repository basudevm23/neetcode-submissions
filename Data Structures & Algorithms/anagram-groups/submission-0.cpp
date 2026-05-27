// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<vector<int>, string> mpp;
        
//         for(string s: strs){
//             vector<int> cnt(26, 0);
//             for(char c: s){
//                 cnt[c-'a']++;
//             }
//             mpp[cnt].append(s);
//         }
//         return mpp.values();
//     }
// };
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mpp;

        for(string s : strs) {

            string key = s;

            sort(key.begin(), key.end());

            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto& [key, value] : mpp) {
            ans.push_back(value);
        }

        return ans;
    }
};