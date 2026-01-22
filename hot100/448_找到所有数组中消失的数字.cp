// 2026.1.22 14点23分
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vv;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1) {
                i++;
                continue;
            }
           
            if(nums[nums[i]-1]==nums[i]){
                i++;
                continue;
            }
            int res=nums[i]-1;
            int tmp=nums[i];
            nums[i]=nums[res];
            nums[res]=tmp;

        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=(i+1))
                vv.push_back(i+1);
        }
        return vv;
    }
};