// 2026.1.25 11点59分
class Solution {
public:
    vector<string> result;
    string path;
    void backtrack(int n,int l_count,int r_count){
        if(l_count<r_count||l_count>n)
            return;
    // 存结果
    if(l_count==n&&r_count==n)
        result.push_back(path);
    path += '('; 
    backtrack(n, l_count + 1,r_count);
    path.pop_back();
    path += ')';
    backtrack(n, l_count, r_count + 1);
    path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n,0,0);//初始化path中左右括号数量均为0
        return result;
    }
};