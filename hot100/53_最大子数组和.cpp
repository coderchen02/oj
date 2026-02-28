// 2.28 21点01分
// 方法一 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=INT32_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=nums[i];//区间和 区间和是正数才会往后走 因为一定会使得子序和增大
            if(count>result)//取区间累计的最大值--相当于不断确定最大子序终止位置
                result=count;
            if(count<=0) count=0;//重置最大子序起始位置
        }
        return result;
    }
};