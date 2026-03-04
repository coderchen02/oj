// 3.4 22点02分
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col ) {
                if (dfs(row, col, 0, board, word, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
    //row：board的行，col：board的列，i：递归的深度也是word的第i个字符，visit：保存board中元素是否访问过
    bool dfs(int row, int col, int i, vector<vector<char>>& board, string& word, vector<vector<bool>>& visit) {
        if (i == word.length()) {
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        if (row >= rows || row < 0 || col >= cols || col < 0 || board[row][col] != word[i] || visit[row][col]) {
            return false;
        }

        visit[row][col] = true;
        bool res = false;
        //向下搜索
        res |= dfs(row + 1, col, i + 1, board, word, visit);
        //向右搜索
        res |= dfs(row, col + 1, i + 1, board, word, visit);
        //向上搜索
        res |= dfs(row - 1, col, i + 1, board, word, visit);
        //向左搜索
        res |= dfs(row, col - 1, i + 1, board, word, visit);
        visit[row][col] = false;

        return res;
    }
};
