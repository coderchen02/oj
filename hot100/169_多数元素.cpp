// 2026.1.21 21点13分
// 哈希算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> counts;
        int majority=0,cnt=0; //majority 存储多数元素 cnt存储当前的多数元素出现的次数
        for(int num:nums){
            counts[num]++;
            if(counts[num]>cnt){
                majority=num;
                cnt=counts[num];
            }
        }
        return majority;
    }
};