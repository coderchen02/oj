// 2026.2.5 22点52分
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]]; 
            if(slow==fast) break;
        }
        slow=0;
        while(true){
            slow=nums[slow];
            fast=nums[fast];
            if(slow==fast) return slow;
        }
        return slow;
    }
};