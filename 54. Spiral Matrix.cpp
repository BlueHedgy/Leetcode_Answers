class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();              // row
        int n = matrix[0].size();           // column

        vector<int> ans;
        if (m == 0 || n == 0) return ans;

        vector<vector<int>> dirs{{0,1}, {1,0}, {0,-1}, {-1,0}};      // Direction matrix
        vector<int> nSteps{n, m-1};
        
        int iDir=0;          // Direction index
        int ir = 0, ic = -1; // Starting position in the matrix

        while (nSteps[iDir%2]){
            for (int i=0; i<nSteps[iDir%2]; i++){
                ir += dirs[iDir][0];
                ic += dirs[iDir][1];
                ans.push_back(matrix[ir][ic]);
            }
            nSteps[iDir%2]--;
            iDir = (iDir + 1)%4;
        }
        return ans;
    }
}; 