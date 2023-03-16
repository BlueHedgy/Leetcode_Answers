using namespace std;
    // Time limit exceeded
    // Why not &grid in dfs function? So the marked visted doesn't affect other paths of DFS when it's checking
    // Maybe this could be fixed by backtracking, that would lower the overhead memory as well
    // BFS seems a better method for this
void dfs(vector<vector<int>> grid, int count, int i, int j, vector<int> &path_length) {
    if (i < 0 || j <0 || i > grid.size()-1 || j > grid[0].size()-1 || grid[i][j] == 1) return;
    count++;
    if (i == grid.size() -1 && j == grid[0].size()-1){
        path_length.push_back(count);
        return;
    }

    vector<int> dir{1, -1, 0, 1, 0, -1, -1, 1, 1}; // Directional vector to check 8 adjacent tiles

    grid[i][j] = 1; //mark visited
        

    for (int ind = 0; ind < 8; ind++){
        int r = i + dir[ind];
        int c = j + dir[ind+1];

        dfs(grid, count, r, c, path_length);
    }
}
    
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int i = 0, j = 0;
    vector<int> path_length;
    int count = 0;

    if (path_length)
    dfs(grid, count, 0, 0, path_length);
    // sort(path_length.begin(), path_length.end());

    return path_length.size() == 0? -1 :  path_length[0];
}



// BFS method

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
                        //  since we return the result here (end tile), the code hasn't had the chance to add 1 
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