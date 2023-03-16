class Solution {
public:
    // Multisource BFS with source being the island tiles

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> queue;

        int n = grid.size();
        int max_dist = -1;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        vector<int> dir{-1, 0, 1, 0, -1};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                visited[i][j] = grid[i][j];
                if (grid[i][j] == 1){
                    queue.push({i,j});
                }
            }
        }

        while (!queue.empty()){
            int size = queue.size();
            while(size--){
                pair<int,int> pos = queue.front();
                queue.pop();
                for (int ind=0; ind < 4; ind++){
                    int r = pos.first + dir[ind];
                    int c = pos.second + dir[ind+1];

                    if (r >= 0 && c >=0 && r<n && c<n && visited[r][c] == 0){
                        visited[r][c] = 1; // Mark visited
                        queue.push({r,c});
                    }
                }
            }
            max_dist++;
        }
        return max_dist == 0? -1 : max_dist;
    }
};