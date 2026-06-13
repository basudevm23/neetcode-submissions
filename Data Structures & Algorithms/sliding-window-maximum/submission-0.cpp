class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // the window slides one position at a time
        // so I should be aware of all max values
        // pop_back and pop_front
        // dq.push_back and push_front
        // front and back elements
        deque<int> dq;
        int l =0;
        int r= 0;
        vector<int> ans;
        while(r<nums.size()){
            while(!dq.empty()&&nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(l>dq.front()){
                dq.pop_front();                
            }
            if(r+1>=k){
                ans.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
