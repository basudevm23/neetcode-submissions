class BrowserHistory {
public:
    stack<string> st;
    stack<string> buffer;
    BrowserHistory(string homepage) {
        st.push(homepage);
    }      
    void visit(string url) {
        st.push(url);
        while(!buffer.empty()){
            buffer.pop();
        }
    }   
    string back(int steps) {
        while(steps > 0 && st.size() > 1){
 
            buffer.push(st.top());
            st.pop();
            steps--;
            
        } 
        return st.top();       
    }
    
    string forward(int steps) {
        while(steps>0&&!buffer.empty()){
            st.push(buffer.top());
            buffer.pop();
            steps--;
        } 
        return st.top();       
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */