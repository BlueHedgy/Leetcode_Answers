class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>> rotten;
        vector<int> dir={-1,0,1,0,-1};

        for (int i=0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) rotten.push({i,j});
            }
        }

        int minute = -1;

        while (!rotten.empty()){
            int size = rotten.size();
            while (size--){
                pair<int, int> p = rotten.front();
                rotten.pop();

                for(int i=0; i<4; i++){
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];

                    if (r>=0 && r<grid.size() &&c>=0 && c< grid[0].size() && grid[r][c]==1){
                        grid[r][c] =2;
                        rotten.push({r,c});
                        fresh--;
                    }
                }

            }
            minute++;
        }
        if (fresh>0) return -1;
        if (minute==-1) return 0;
        return minute;

    }
};