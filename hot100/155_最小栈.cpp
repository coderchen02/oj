// 2026.1.30 23点03分
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(st_min.empty())   st_min.push(val); 
        else st_min.push(min(val,st_min.top()));    //存相对的较小值
    }
    
    void pop() {
        st.pop();
        st_min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
private:
    stack<int> st;     //保存栈中的元素
    stack<int> st_min;//保存栈中最小的元素
};
