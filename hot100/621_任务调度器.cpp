// 3.2 19点34分
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(auto type:tasks)
            cnt[type-'A']++;//得出每个字母出现的次数
        int cnt_max=0,equal_cnt_max=-1;//equal_cnt_max 表示出现次数和cnt_max相等的任务有多少个
        for(int i=0;i<cnt.size();i++)
            cnt_max=max(cnt[i],cnt_max);//找出出现次数最多的任务
        
        for(int i=0;i<=25;i++)
            if(cnt_max==cnt[i])
                equal_cnt_max++;//统计出现次数与最大次数相同的任务总个数
        /*当任务种类非常多或者冷却时间 n 非常小时，即使按部就班地安排任务，空闲插槽（Idle slots）也会被填满，甚至不够填。
        这时候，你完全不需要任何“等待期”，可以直接把所有任务排满。
        */
        return max((cnt_max-1)*n+cnt_max+equal_cnt_max,(int)tasks.size());
    }
};