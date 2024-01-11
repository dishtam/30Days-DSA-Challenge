/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(TreeNode* node,int par){
        if(!node) return;
        if(par!=-1){
            adj[par].push_back(node->val);
            adj[node->val].push_back(par);
        }
        dfs(node->left,node->val);
        dfs(node->right,node->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,-1);
        queue<pair<int,int>> q; // node,dist;
        int maxDist=0;
        q.push({start,0});
        unordered_set<int> vis;
        vis.insert(start);

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dist = it.second;

            maxDist =  max(maxDist,dist);
            for(auto neigh:adj[node]){
                if(vis.find(neigh)==vis.end()){
                    q.push({neigh,dist+1});
                    vis.insert(neigh);
                }
            }
        }
        return maxDist;
    }
};
