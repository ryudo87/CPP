//re-use first row/col to record if to set entire row/col zero, use two extra vars to record if first row/col have 0
class Solution {
public:
    // space O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_col_has_zero = false, first_row_has_zero = false;
        for (int i=0;i<matrix.size();++i) {
            if (0 == matrix[i][0]) {
                first_col_has_zero = true;break;
            }
        }
        for (int j=0;j<matrix[0].size();++j) {
            if (0 == matrix[0][j]) {
                first_row_has_zero = true;break;
            }
        }
        
        for (int i=1;i<matrix.size();++i) {
            for (int j=1;j<matrix[0].size();++j) {
                if (matrix[i][j] == 0) {
                    // reuse first row and col
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); ++i)
            for (int j = 1; j < matrix[0].size(); ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        if (first_col_has_zero) {
            for (int i=0;i<matrix.size();++i) {
                matrix[i][0] = 0;
            }
        }
        
        if (first_row_has_zero) {
            for (int j=0;j<matrix[0].size();++j) {
                matrix[0][j] = 0;
            }
        }
    }
};
