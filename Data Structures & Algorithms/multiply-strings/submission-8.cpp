class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        // the number of digits in the output is lesser than the sum of digits in the multipliers
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> num((num1.size() + num2.size()), 0);
        for(int i=0; i<num1.size(); i++){
            for(int j=0; j<num2.size();j++){
                int digit = (num1[i]-'0')*(num2[j]-'0');
                num[i+j] +=digit;
                num[i+j+1] += num[i+j]/10;
                num[i+j] = num[i+j]%10;
            }
        }
        for(int i = 0; i < num.size() - 1; i++) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
        reverse(num.begin(), num.end());
        string s = "";
        int r = 0;
        while(r<num.size()){
            s += char(num[r] + '0');
            r++;
        }
        int i=0;
        while(i < num.size() && num[i] == 0){
            i++;
        }
        s.erase(0,i);
        return s;
    }
};
