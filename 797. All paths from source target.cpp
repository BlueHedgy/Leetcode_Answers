class Solution {
public:
    void backtrack(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &temp, int curr_node){
        // Push back node to temp vector
        temp.push_back(curr_node);

        // Add temp to ans if the code reaches the end index of graph
        if (curr_node == graph.size()-1){
            ans.push_back(temp);
        }
        
        // Perform backtracking for each element in a graph's index aka connected node to current node
        for (int i = 0; i < graph[curr_node].size(); i++){
            backtrack(graph, ans, temp, graph[curr_node][i]);
        }

        temp.pop_back();      
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        // Call backtrack function with index 0 of graph, aka Node 0
        backtrack(graph, ans, temp, 0);
        return ans;
    }
};