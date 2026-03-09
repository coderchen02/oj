//3.9 22点16分
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> marks(s.length(),false);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else{//遍历到右括号
                if(!st.empty()){
                    int j=st.top();
                    st.pop();
                    marks[i]=true;
                    marks[j]=true;
                }
            }
        }
        int maxLen=0;//最长的标记为true的长度
        int curLen=0;//当前的标记为true的长度
        for(auto mark:marks){
            if(mark){
                ++curLen;
                maxLen=max(maxLen,curLen);
            }else
                curLen=0;
        }
        return maxLen;
    }
};