// 2026.1.23 20点46分
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int left=-1,right=0;right<nums.size();right++)
            if(nums[right]!=0)
                swap(nums[++left],nums[right]);
    }
};

//自己写的
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=-1;
        int right=0;   //left记录是非零集合的最后一个元素位置
        while(right<nums.size()){
           if(nums[right]==0){
                right++;
                continue;}
            //此时right位置上的一定是个非零元素
            if(nums[right]!=0){
                left++;
                swap(nums[left],nums[right]);
                right++;
            }
        }
    }
};