// 3.9 22点03分
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int r=0,l=1;//这个初始化可以特判数组本来就是有序的情况 最后的结果r-l+1=0 
        int max=nums[0],min=nums[n-1];
        for(int i=0;i<n;i++){
            //从前往后遍历，维护最大值max,最后一个不满足nums[i]>max的值，既为无序数组的有边界
            if(nums[i]<max) //如果当前的数 nums[i] 比 max 还要小，说明 nums[i] 站在了错误的位置（它前面有比它大的数），因此它必须被包含在待排序范围内。
                r=i;
            else
                max=nums[i];

            //从后往前遍历，维护最小值，最后一个不满足nums[i]<=min的值，既为无序数组的左边界
            if(nums[n-i-1]>min)//如果当前的数 nums[n-i-1] 比 min 还要大，说明这个数也站错了位置（它后面有比它小的数）。
                l=n-i-1;
            else 
                min=nums[n-1-i];
        }
        return r-l+1;
    }
};