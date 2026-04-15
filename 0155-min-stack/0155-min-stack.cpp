class MinStack {
public:
    stack<int>st;
    stack<int>dec;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(dec.empty()||dec.top()>=x){
            dec.push(x);
        }else{
        dec.push(dec.top());
        }
    }
    
    void pop() {
        st.pop();
        dec.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
      return dec.top();  
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */