// 3.6 20点52分
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        我们要找的是一个连续子数组 [i, j]，使得其元素之和等于 k
        既找到满足以下条件的组合：s[j]-s[i]=k      s代表前缀和
        当我遍历到位置 j（当前前缀和为 cur_sum）时，我只需要看看在 j 之前，有多少个位置 i 的前缀和等于 cur_sum - k
        如果有，那么这些位置到 j 之间的子数组和就一定等于 k。
        */
        int result=0;
        unordered_map<int,int> u_map; //key:前缀和 value:这个前缀和出现的次数
        int cur_sum=0;//表示当前前缀和
        u_map[cur_sum]=1;//
        for(int i=0;i<nums.size();i++){
            cur_sum+=nums[i];
            if(u_map[cur_sum-k]) //如果这个前缀和出现的次数不为0
                result+=u_map[cur_sum-k];
            u_map[cur_sum]++;
        }
        return result;
    }
};