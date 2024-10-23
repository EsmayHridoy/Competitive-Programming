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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        TreeNode* current = root;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(current);

        int levelSize = 1;
        while(!nodeQueue.empty()) {
            vector<TreeNode*> currentLevelNodes;
            levelSize = nodeQueue.size();

            int levelSum = 0;
            while(levelSize--) {
                current = nodeQueue.front();
                nodeQueue.pop();
                if(current->left) {
                    levelSum += current->left->val;
                }
                if(current->right) {
                    levelSum += current->right->val;
                }
                currentLevelNodes.push_back(current);
            }

            while(!currentLevelNodes.empty()) {
                current = currentLevelNodes.back();
                currentLevelNodes.pop_back();
                int childSum = 0;
                if(current->left) {
                    childSum += current->left->val;
                    nodeQueue.push(current->left);
                }
                if(current->right) {
                    childSum += current->right->val;
                    nodeQueue.push(current->right);
                }

                if(current->left) {
                    current->left->val = levelSum - childSum;
                }
                if(current->right) {
                    current->right->val = levelSum - childSum;
                }
            }
        }

        return root;
    }
};
