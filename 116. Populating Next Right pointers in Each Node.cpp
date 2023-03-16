/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void level_order(Node*root, int level, map<int, vector<Node*>> &node_levels){
        if (root == NULL) return;
        
        node_levels[level].push_back(root);
        level +=1;

        level_order(root->left, level, node_levels);
        level_order(root->right, level, node_levels);
    }

    Node* connect(Node* root) {
        map<int, vector<Node*>> node_levels;
        int level=0;

        // BFS traversal to find level order
        level_order(root, level, node_levels);

        for (int i=0; i<node_levels.size(); i++){
            for (int j=0; j < node_levels[i].size(); j++){
                if(j+1 >= node_levels[i].size()) node_levels[i][j]->next = NULL;
                else node_levels[i][j]->next = node_levels[i][j+1];
            }
        }
        return root;
    }
};