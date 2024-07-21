class MinStack {
public:
    
    struct data {
        int val;
        int min_val;
    };
    stack<data> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        else {
            st.push({val, min(val, st.top().min_val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().val;
    }
    
    int getMin() {
        return st.top().min_val;
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