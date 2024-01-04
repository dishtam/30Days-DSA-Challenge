struct Node {
    int sum;
    int minVal;
    int maxVal;
    bool isBst;

    Node() {
        sum = 0;
        minVal = INT_MAX;
        maxVal = INT_MIN;
        isBst = false;
    }
};

class Solution {
public:
    Node* solve(TreeNode* node, int& maxi) {
        Node* root = new Node();
        if (!node) {
            root->isBst = true;
            return root;
        }
        
        Node* left = solve(node->left, maxi);
        Node* right = solve(node->right, maxi);

        if (left->isBst && right->isBst && node->val > left->maxVal && node->val < right->minVal) {
            root->isBst = true;
            root->sum = node->val + left->sum + right->sum;
            root->minVal = min(left->minVal, node->val);
            root->maxVal = max(right->maxVal, node->val);

            maxi = max(maxi, root->sum);
        }
        return root;
    }

    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        Node* result = solve(root, maxi);
        delete result; 
        return maxi;
    }
};
