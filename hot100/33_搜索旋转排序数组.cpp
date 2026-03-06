// 3.6 21点16分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            //如果mid落在左边的递增区间
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target&&target<nums[mid])
                    right=mid-1;
                else 
                    left=mid+1;
            }
            else{
                //mid落在右边的递增区间
                if(target>nums[mid]&&target<=nums[right])
                    left=mid+1;
                else 
                    right=mid-1;
            }
        }
        return -1;
    }
};