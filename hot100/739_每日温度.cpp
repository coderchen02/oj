// 2026.2.2 21点59分
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;   //栈用来存下标
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty()&&temperatures[i]>temperatures[st.top()]){
                int index=st.top();
                res[index]=i-index;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};