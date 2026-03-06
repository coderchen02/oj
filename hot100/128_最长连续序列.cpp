//3.6 20点03分
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result=0;
        unordered_set<long long> u_set;
        for(int i=0;i<nums.size();i++)
            u_set.emplace(nums[i]);
        for(auto& num : u_set){//注意这个不要遍历nums 因为有可能有重复元素出现多次导致过不了 而set会自动去重所以能过
            if(u_set.find(num-1)==u_set.end()){//如果他的左边没有 那么说明它可以作为起始位置
                int len=0;
                while(u_set.find(num+len)!=u_set.end()){
                    len++;
                    result=max(result,len);
                }

            }
        }
        return result;
    }
};