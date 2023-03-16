class Solution {
public:
    // The idea is to perform BFS from top left, spreading and adding to the distance every bds round
    // the distance of the round that reaches end tile first is minimum

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //  The problem doesn't seem to consider the {0,0} == 1 being an edge case
        //  we should take that into consideration anyway
        if (grid[0][0] != 0 || grid[n-1][n-1] == 1) return -1;

        // if the matrix just contains one element we have to return 1 right away
        // due to the method in this code adding 1 to distance every eligible check
        if (n == 1) return 1;
        
        queue<pair<int, int>> q;

        // This visited grid should be the better practice instead of modifying input grid
        // but here i will proceed with the modification anyway
        vector<vector<int>> visited(n, vector<int>(n, 0));

        q.push({0, 0});

        vector<int> dir{1, -1, 0, 1, 0, -1, -1, 1, 1}; // 8 adjacent tiles direction vector;
        int dist = 1;   // since the path length consider first tile into the length as well
    
        while (!q.empty()){
            int size = q.size();
            while (size--){
                pair<int, int> pos = q.front();
                q.pop();

                for (int ind = 0; ind < 8; ind++){
                    int r = pos.first + dir[ind];
                    int c = pos.second + dir[ind+1];

                    if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 0){
                        grid[r][c] = 1; //Mark visited
                        if (r == n-1 && c == n-1){ 
                            //  since we return the result here, the code hasn't had the chance to add 1 
                            //  to dist when visiting the end tile, hence we do that manually
                            dist++;
                            return dist;
                        } 
                        q.push({r,c});
                    }
                }
            }
            // Add 1 to dist after every eligible 0 tile check(after every BFS)
            dist++;
        }
        return -1;        
    }
};