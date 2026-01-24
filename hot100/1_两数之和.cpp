//2026.1.24  19点44分
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> map;  //map 的key是数组元素 value是数组下标
        for(int i=0;i<nums.size();i++){
            int res=target-nums[i];//要查找的目标值
            auto iter=map.find(res);
            if(iter!=map.end()){
                //找到了
                ans.push_back(i);
                ans.push_back(iter->second);
            }
            //没找到
            map.insert(make_pair(nums[i],i));
        }
        return ans;
    }
};