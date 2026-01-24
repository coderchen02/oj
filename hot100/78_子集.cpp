// 2026.1.24 20点42分
class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void backtrack(vector<int>&nums,int startIndex){
        result.push_back(path);  //收集子集 ，要放在终止添加上面，否则会漏掉自己
        if(startIndex>=nums.size()) return;
    for(int i=startIndex;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrack(nums,i+1);
        path.pop_back();
    }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtrack(nums,0);
        return result;
    }
};