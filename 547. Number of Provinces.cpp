class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[i] = true; 
        for (int j = 0; j < visited.size(); j++){
            if (i != j && isConnected[i][j] == 1 && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0) return 0;

        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < visited.size(); i++){
            if (!visited[i]){
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;   
    }
};