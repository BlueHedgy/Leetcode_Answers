class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int i, int j, int &count){
        // Edge cases (literally of the map) and skip the 0 tiles
        if (i<0 || j<0 || i>(r-1) || j>(c-1) || grid[i][j] != 1) return;

        if (grid[i][j] == 1){
            count +=1;
            grid[i][j] = 0;    // To mark as visited island "1" tiles

        
            // DF Search 4 adjacent tiles from the current i, j position
            dfs(grid, r, c, i-1, j, count);
            dfs(grid, r, c, i, j-1, count);
            dfs(grid, r, c, i+1, j, count);
            dfs(grid, r, c, i, j+1, count);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                int count=0;
                dfs (grid, r, c, i, j, count);

                // Keep replacing max with the highest area count value for each island found  
                if (count > max) max = count;  
            }
        }
        return max;
    }
};