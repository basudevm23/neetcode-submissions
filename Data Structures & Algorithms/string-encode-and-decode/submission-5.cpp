class Solution {
    
public:
    string encode(vector<string>& strs) {
        string res = "";

        for(auto s: strs){
            res += to_string(s.length()) + "," + s;
        }

        return res;
    }

    vector<string> decode(string s) {

        int i = 0;
        vector<string> res;

        while(i < s.length()){
            int j = i;

            while(s[j]!=','){
                j++;
            }
            int number = stoi(s.substr(i, j-i));

            res.push_back(s.substr(j+1, number));

            i = j+1 + number;
        }
        return res;
           
    }
};
