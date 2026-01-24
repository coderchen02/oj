// 2026.1.24 21点00分
class Solution {
public:
    vector<int>path;
    vector<vector<int>>result;
    void backtracking(vector<int>&nums,vector<bool>& used){
        if(path.size()==nums.size()) { //此时说明找到一组结果了
            result.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;//path里面已经收录的元素，直接跳过
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        result.clear();
        vector<bool>used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};