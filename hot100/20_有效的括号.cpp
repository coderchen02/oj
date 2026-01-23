// 2026.1.23 21点12分
class Solution {
public:
    bool isValid(string s) {
       bool flag=true;
       if(s[0]==']'||s[0]=='}'||s[0]==')') return false;
       if(s.size()==1) return false;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                st.push(s[i]);
            if(s[i]==')'||s[i]==']'||s[i]=='}')//如果遇到右
            {
                if(st.size()==0) return false;
                if(st.top()=='('&&s[i]!=')'||
                    st.top()=='['&&s[i]!=']'||
                    st.top()=='{'&&s[i]!='}') return false;
                st.pop();
            }

        }
        if(st.size()!=0) flag= false;
        return flag;
    }
};