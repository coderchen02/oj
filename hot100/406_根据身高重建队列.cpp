// 2.28 22点19分
class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>& b){
        // 第一步：判断a和b的身高（[0]位置）是否相等
        // 身高相等时：k值小的排在前面（a[1] < b[1]）
        if(a[0]==b[0]) return a[1]<b[1];
        // 第二步：身高不相等时：身高高的排在前面（a[0] > b[0]）
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>que;
        for(int i=0;i<people.size();i++){
            int position=people[i][1];//这个元素要插入的位置
            que.insert(que.begin()+position,people[i]);
        }
        return que;
    }
};