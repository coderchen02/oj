//3.2 22点24分
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                string tmp;
                tmp = tmp + s[i];
                st.push(tmp);

            } else {        // 碰到了右括号
                string tmp; // 目前处理的子串
                while (st.top() != "[") {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop(); // 弹出左括号
                string num;
                while (!st.empty() && isdigit((st.top())[0])) {
                    num = st.top() + num;
                    st.pop();
                }
                string str;
                int cnt = stoi(num);
                while (cnt) {
                    str = str + tmp;
                    cnt--;
                }
                st.push(str);
            }
        }
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};