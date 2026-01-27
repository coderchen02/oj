// 时间：2026.1.6 22点36分
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //left:已处理的区间内，非零元素的最后一个位置
        //right:从左往右遍历数组
        int left=-1,right=0;
        while(right!=nums.size())
        {
            if(nums[right]!=0) 
            {
                left++;
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
            }
             right++;
        }
    }
};