class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> hashs1(26, 0), hashs2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            hashs1[s1[i] - 'a']++;
            hashs2[s2[i] - 'a']++;
        }

        int matches = 0; 
        for (int i = 0; i < 26; i++) {
            if (hashs1[i] != hashs2[i])
                matches++;
        }

        if (matches == 0) return true;

        for (int i = s1.size(); i < s2.size(); i++) {

            int add = s2[i] - 'a';
            int rem = s2[i - s1.size()] - 'a';

           
            if (hashs1[rem] == hashs2[rem]) matches++;
            hashs2[rem]--;
            if (hashs1[rem] == hashs2[rem]) matches--;

          
            if (hashs1[add] == hashs2[add]) matches++;
            hashs2[add]++;
            if (hashs1[add] == hashs2[add]) matches--;

            if (matches == 0) return true;
        }

        return false;
    }
};