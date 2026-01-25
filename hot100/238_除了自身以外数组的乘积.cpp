// 2026.1.25 21点13分
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //需要求出前缀积数组
        vector<int>lnums=nums;
        int pre=1;
        for(int i=0;i<nums.size();i++){
            lnums[i]=pre;
            pre*=nums[i];
        }
        //求出后缀积数组
        vector<int>rnums=nums;
        pre=1;
        for(int j=nums.size()-1;j>=0;j--){
            rnums[j]=pre;
            pre*=nums[j];
        }
        for(int i=0;i<nums.size();i++)
            nums[i]=lnums[i]*rnums[i];
        return nums;
    }
};