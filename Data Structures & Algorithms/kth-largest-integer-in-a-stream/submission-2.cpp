class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        x = k;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int n = nums.size();
        while(n>k){
            pq.pop();
            n--;
        }
    }
    int add(int val) {
        pq.push(val);
        int n = pq.size();
        while(n>x){
            pq.pop();
            n--;        
        }
        return pq.top();       
    }
};
