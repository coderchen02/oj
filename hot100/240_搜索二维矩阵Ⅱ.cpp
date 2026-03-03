// 3.3 21点19分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startRow = 0, startCol = matrix[0].size() - 1;
        while (startCol >= 0 && startRow < matrix.size()) {
            if (matrix[startRow][startCol] == target)
                return true;
            else if (matrix[startRow][startCol] < target)
                startRow++;
            else if (matrix[startRow][startCol] > target)
                startCol--;
        }
        return false;
    }
};