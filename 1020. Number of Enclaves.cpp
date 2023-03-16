class Solution {
public:
    void dfs(vector<vector<int>> &grid, int &count, int i, int j, bool &enclaved){
        if (i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size() -1) {
            enclaved = false;
            return;
        }

        if (grid[i][j] == 0) return;

        grid[i][j] = 0; // Mark visited
        count +=1;

        vector<int> dir{-1,0,1,0,-1};
        int water_or_isle = 0;
        for (int ind = 0; ind < 4; ind++){
            int r = i + dir[ind];
            int c = j + dir[ind + 1];

            dfs(grid, count, r, c, enclaved);
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int moves = 0;
        for (int i = 0; i < m ; i++){
            for (int j = 0; j < n ; j++){
                if (grid[i][j] == 1){
                    int count = 0;
                    bool enclaved = true;
                    dfs(grid, count, i, j, enclaved);

                    if (enclaved == true){
                        moves += count;
                    }
                }
            }
        }
        return moves;
    }
};