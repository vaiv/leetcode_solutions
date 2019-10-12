/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void find(TreeNode* root, int current_min, int current_max, int& res)
    {
        if(!root)
            return;
        
        current_min == INT_MAX ? current_min = root->val : 0;
        current_max == INT_MIN ? current_max = root->val : 0;
            
        res = max(res, max(abs(current_min - root->val), abs(current_max - root->val)));
        
        current_min > root->val ? current_min = root->val : 0;
        current_max < root->val ? current_max = root->val : 0;
        
        find(root->left, current_min, current_max, res);
        find(root->right, current_min, current_max, res);
        
        return;
        
    }
    
    
    int maxAncestorDiff(TreeNode* root) 
    {
        // Make a set of ancestors and subtract with min and max values
        // Instead of using set use min and max values which is what essentially 
        // we are looking for in the set
        int current_max = INT_MIN;
        int current_min = INT_MAX;
        int res = INT_MIN;
        find(root, current_min, current_max, res);
        return res;
        
    }
};