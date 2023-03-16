class Solution {
public:
    void dfs(vector<vector<char>> &grid, int &count, int i, int j){
        vector<int> dir={-1,0,1,0,-1};      // Direction vector for adjacent DFS

        // Check if i and j go out of the map's border
        if (i<0 || j<0 || i>grid.size()-1 || j > grid[0].size()-1 || grid[i][j] != '1') return;

        grid[i][j] = '0';       // Mark visited island tiles

        // Performing DFS on adjacent tiles
        for (int ind = 0; ind < 4; ind++){
            int r =  i + dir[ind];
            int c =  j + dir[ind+1];
            dfs(grid, count , r, c);
        }   
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row;  i++){
            for (int j = 0; j < col; j++){
                if(grid[i][j] == '1') {
                    dfs(grid, count, i, j);
                    count +=1;
                }
            }
        }

        return count;
    }
};