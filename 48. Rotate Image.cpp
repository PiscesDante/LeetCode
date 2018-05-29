class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        // phase one
        for (int head = 0, tail = row - 1; head < tail; ++head, --tail)
            swap(matrix[head], matrix[tail]);
        // phase two
        for (int i = 0; i < row; ++i) {
            for (int j = i; j < column; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // end
    }
};

// 执行用时：8 ms
// 已经战胜 16.38 % 的 cpp 提交记录