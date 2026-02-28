// 2.28 22点52分
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size()==0) return result;
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(result.back()[1]>=intervals[i][0]){//发现重叠区间
                //合并区间 只更新右边界就好
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else result.push_back(intervals[i]);//区间不重叠
        }
        return result;
    }
};