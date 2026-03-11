// 3.11 22点28分
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums=0;
        int rows=grid.size();
        if(!rows) return nums;
        int cols=grid[0].size();
        vector<vector<bool>>visit(rows,vector<bool>(cols,false));
        for(int row=0;row<rows;++row)
            for(int col=0;col<cols;++col){
                if(grid[row][col]=='1'&&!visit[row][col]){
                    bfs(grid,row,col,visit);
                    ++nums;
                }

            }
            return nums;
    }
    void bfs(vector<vector<char>>& grid,int row,int col,vector<vector<bool>>&visit){
        queue<pair<int,int>>q;
        q.push({row,col});
        visit[row][col]=true;
        while(!q.empty()){
            pair<int,int> tmp=q.front();
            q.pop();
            vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
            for(int i=0;i<dirs.size();i++){
                int tmp_row=tmp.first+dirs[i][0];
                int tmp_col=tmp.second+dirs[i][1];
                if(tmp_row>=0&&tmp_row<grid.size()&&tmp_col>=0&&tmp_col<grid[0].size()&&
                grid[tmp_row][tmp_col]=='1'&&!visit[tmp_row][tmp_col]){
                    q.push({tmp_row,tmp_col});
                    visit[tmp_row][tmp_col]=true;
                }
            }
        }
    }
};