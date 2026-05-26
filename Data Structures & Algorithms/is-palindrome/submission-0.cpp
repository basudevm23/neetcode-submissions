class Solution {
public:
    bool check(char str){
        return ('a' <= str && str<= 'z') || ('A' <=str && str <= 'Z') || ('0' <= str&& str <= '9');

    }
    bool isPalindrome(string s) {
        int n = s.size();  
        int left = 0;
        int right = n-1;  
        while(left<right){
            while(left<right && !check(s[left])){
                left++;
            }
            while(left < right && !check(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        } 
        return true;  
    }
};
