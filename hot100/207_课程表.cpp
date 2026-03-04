// 3.4 19点54分
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ingree(numCourses,0);//存每个课程的入度
        unordered_map<int,vector<int>> preCourse;
        for(int i=0;i<prerequisites.size();i++){
            //存储递推关系
            preCourse[prerequisites[i][0]].push_back(prerequisites[i][1]);
            ingree[prerequisites[i][1]]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(!ingree[i]){
                q.push(i);
                cnt++;
            }
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0;i<preCourse[cur].size();i++){
                ingree[preCourse[cur][i]]--;//将cur指向的节点的入度-1
                if(!ingree[preCourse[cur][i]]){
                    q.push(preCourse[cur][i]);//如果减完之后节点入度为零，则添加进队列
                    cnt++;
                }
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};