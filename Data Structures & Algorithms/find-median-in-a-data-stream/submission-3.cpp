class MedianFinder {
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }        

        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size()==largeHeap.size()){
            return (largeHeap.top() + smallHeap.top())/2.0;
        }

        else if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }

        else{
            return largeHeap.top();
        }
        
    }
};
// the min heap keeps the smallest elements at the top
// the max heap keeps the largest element at the top
// so max heap for the lower half would keep the larger elements at the top and
// the min heap would keep the smaller elements at the top
// thus allowing for direct pq.top() and taking their averages
