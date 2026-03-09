// 3.9 21点32分
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //cur_max记录以当前位置结尾的最大乘积（期待更大的正数）
        //cur_min记录以当前位置结尾的最小乘积（期待遇到负数，从而翻转成巨大的正数）。
        int max_res=nums[0];
        int cur_max=nums[0],cur_min=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp_min=cur_min,temp_max=cur_max;
            cur_max=max(max(temp_max*nums[i],temp_min*nums[i]),nums[i]);
            cur_min=min(min(temp_max*nums[i],temp_min*nums[i]),nums[i]);
            max_res=max(max_res,cur_max);
        }
        return max_res;
    }
};