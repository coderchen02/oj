//3.17 20点31分
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int slow=0; 
        for(int fast=0;fast<=n-1;fast++){//快指针扫描数组
            if(nums[fast]!=val) {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};