// 2026.2.9 16点44分
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int i=0;
        while(i<=right){
            if(nums[i]==0) {
                swap(nums[i],nums[left]);
                i++;
                left++;
            }else if(nums[i]==2){
                swap(nums[i],nums[right]);
                right--;
            }else{
                i++;
            }
        }
    }
};