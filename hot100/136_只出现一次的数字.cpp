// 2026.1.21 21点33分
//哈希
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> counts;
        for(int num:nums){
            counts[num]++;
        }
        for(int num:nums)
            if(counts[num]==1) return num;
        return 0;
    }
};