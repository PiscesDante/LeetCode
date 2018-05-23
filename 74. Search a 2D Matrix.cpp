class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size();
        int column = matrix[0].size();
        int row_pos = 0;
        int column_pos = column - 1;
        while (row_pos < row && column_pos >= 0) {
            if (target > matrix[row_pos][column_pos]) ++row_pos;
            else if (target < matrix[row_pos][column_pos]) --column_pos;
            else return true;
        }
        return false;
    }
};

// 执行用时：12 ms
// 已经战胜 62.07 % 的 cpp 提交记录