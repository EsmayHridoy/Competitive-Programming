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
    int ans=0;
    
    pair<int,int> dfs(TreeNode* node)
    {
        if(node == nullptr){
            return {0,0};
        }
        int sum = 0;
        int cn = 0;

        pair<int,int>lf,ri;
        lf=dfs(node->left);
        ri=dfs(node->right);
        sum=lf.first+ri.first+node->val;
        cn=lf.second+ri.second+1;

        if(sum/cn == node->val)ans++;

        return {sum,cn};

    }

    
    int averageOfSubtree(TreeNode* root) {
        
        pair<int,int>gar =dfs(root);
        return ans;
    }
};