#include <cmath>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int  n =digits.size();
        int ones=1;
        int index=0;
        while(ones){
            if(index<n){
                if(digits[index]==9){
                    digits[index]=0;
                }
                else{
                    digits[index]+=1;
                    ones=0;
                }
            }
            else{
                digits.push_back(1);
                ones = 0;

            }
            index++;
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
