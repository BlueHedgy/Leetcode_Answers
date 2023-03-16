class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> zero;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, INT_MAX)); // Distance matrix as answer
        
        vector<int> dir={-1,0,1,0,-1};       // Direction matrix, 4 adjacents

        // Enqueue the zero tiles
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0) {
                    zero.push({i,j});
                    ans[i][j] = 0;
                }
                // Loop through the zero tiles' locations
            }
        }

        while (!zero.empty()){
            pair<int, int> pos  = zero.front();
            zero.pop();

            for (int i=0; i<4; i++){
                int r = pos.first + dir[i];
                int c = pos.second + dir[i+1];

                if (r>=0 && c>=0 && r<m && c<n){
                    if (ans[r][c] > ans[pos.first][pos.second] +1){
                        ans[r][c] = ans[pos.first][pos.second] +1;
                        zero.push({r,c});
                    }
                }
            }
        }
        return ans;
    }
};