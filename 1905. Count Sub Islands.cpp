class Solution {
public:
    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, int &res){
        if (i <0 || j < 0 || i > grid1.size()-1 || j > grid1[0].size()-1) return;

        if(grid1[i][j] == 0 && grid2[i][j] == 1) res = false;

        if (grid2[i][j] == 0) return;

        grid2[i][j] = 0; // Mark visited

        vector<int> dir{-1, 0, 1, 0, -1};

        for (int ind = 0; ind < 4; ind ++){
            dfs(grid1, grid2, i+dir[ind], j + dir[ind+1], res);
        }

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    int res = true;
                    dfs(grid1, grid2, i, j, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};