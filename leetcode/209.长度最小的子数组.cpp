// 3.17 21点08分  时间复杂度：O(n) 空间复杂度:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT_MAX;
        int sum=0;//滑动窗口和
        int i=0;//滑动窗口起始位置
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                result=min(result,j-i+1);
                sum-=nums[i];
                i++;
            }

        }
        if(result==INT_MAX) return 0;
        return result;
    }
};