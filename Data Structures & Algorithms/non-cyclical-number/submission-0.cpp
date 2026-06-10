class Solution {
public: 
    int sqgenerator(int n){
        int output= 0;
        while(n){
            int digit = n%10;
            output += pow(digit, 2);
            n = n/10;
        }
        return output;
    }
    bool isHappy(int n) {
        set<int> st;
        while(st.find(n)==st.end()){
            st.insert(n);
            n = sqgenerator(n);
            if(n==1) return true;
        }  
        return false;      
    }
};
