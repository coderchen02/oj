// 2026.1.27 21点29分
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 假设前面+号的集合为left 前面-号的集合为right
        // left + right=sum; 1式
        // left - right=target 2式
        //1式解出right=sum-left 然后代入2式
        //解得 left=(sum+target)/2 所以问题转换为数组出元素凑出left的方法数 0-1背包
        //dp[j] 容量为j有dp[j]种方法
        /*
        假设我们有数字1 那么dp[4]凑数dp[5]
        假设我们有数字2 那么dp[3]凑数dp[5]
        假设我们有数字3 那么dp[2]凑数dp[5]
        ...所以dp[5]=dp[1]+dp[2]+dp[3]+dp[4]+dp[0]
        抽象为dp[j]+=dp[j-nums[i]]
        */
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(abs(target)>sum) return 0;
        if((target+sum)%2==1) return 0;
        int bagSize=(target+sum)/2;
        vector<int>dp(bagSize+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){   //遍历物品
            for(int j=bagSize;j>=nums[i];j--) //遍历背包
                dp[j]+=dp[j-nums[i]];
        }
        return dp[bagSize];
    }
};