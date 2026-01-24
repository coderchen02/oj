// 2026.1.24 21点51分
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //图像位置的变化满足mat[row][col]---->mat[col][n-1-row]
        //但是题目要求只能在原地修改图像，所以不可以另外创建二维数组来进行操作
        //原地想实现这个位置变换可以通过一次水平翻转和一次主对角线翻转来完成
        //水平线上下翻转的结果： mat[row][col]--->mat[n-1-row][col]
        //主对角线翻转的结果是:  mat[row][col]--->mat[col][row]

        vector<int>res=matrix[0];
        int n=res.size();
        //水平翻转一次
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
        //主对角线翻转一次
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};