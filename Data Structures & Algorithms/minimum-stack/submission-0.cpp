class MinStack {
private:
    vector<int> ans;
public:
    MinStack() {
    }  
    void push(int val) {
        ans.push_back(val);             
    } 
    void pop() {
        ans.pop_back();           
    }
    int top() {
        return ans.back();   
    }
    int getMin() {
        return *min_element(ans.begin(),ans.end());     
    }
};
