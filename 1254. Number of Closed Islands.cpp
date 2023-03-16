class Solution {
public:
   bool dfs(vector<vector<int>> &grid, int &count, int i, int j){
        vector<int> dir={-1,0,1,0,-1};      // Direction vector for adjacent DFS

        if (i < 0 || j < 0 || i > grid.size()-1|| j > grid[0].size()-1){
            return false;
        }
        if (grid[i][j] == 1){
            return true;
        }

        grid[i][j] = 1;

        int water_or_isle = 0;
        // The idea is to check whether the surrounding of each tile is surrounded by water and island tile,
        // all 4 DFS Should be true and the original DFS needs to be true to add 1 to island count
        for (int ind = 0; ind < 4; ind++){
            int r = i + dir[ind];
            int c = j + dir[ind+1];
            if (dfs(grid, count, r, c) == true){
                water_or_isle++;
            };
        }

        if (water_or_isle == 4){
            return true;
        }

        return false;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 0){
                    if (dfs(grid, count, i, j) == true) count += 1;
                    // count +=1;
                }
            }
        }
        return count;
    }
};