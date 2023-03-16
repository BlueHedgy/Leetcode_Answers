class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Tranpose the matrix
        int temp;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Flip along column
        for (int i=0; i<n; i++){
            for (int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};