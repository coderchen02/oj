// 3.6 20点29分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=binSearch(nums,target,true);
        int right=binSearch(nums,target,false);
        return {left,right};
    }
    int binSearch(vector<int>& nums,int target,int isLeft){
        int left=0,right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else {//mid指针指向的元素等于target
                index=mid;
                if(isLeft){//如果我们找的是左边界
                    right=mid-1;
                }
                else{//如果我们找的是右边界
                    left=mid+1;
                }
            }
        }
        return index;
    }
};