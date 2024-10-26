// 2458. Height of Binary Tree After Subtree Removal Queries
// Cpp Solution


class Solution {
private:
    vector<int> parentNode;
    vector<int> nodeDepth;
    vector<TreeNode*> nodeMap;
    
    int depthFirstSearch(TreeNode* currentNode) {
        if (currentNode == nullptr) return 0;
        nodeMap[currentNode->val] = currentNode;
        int leftDepth = 0, rightDepth = 0;
        leftDepth = depthFirstSearch(currentNode->left);
        rightDepth = depthFirstSearch(currentNode->right);

        if (currentNode->left) parentNode[currentNode->left->val] = currentNode->val;
        if (currentNode->right) parentNode[currentNode->right->val] = currentNode->val;

        return nodeDepth[currentNode->val] = max(leftDepth, rightDepth) + 1;
    }

public:
    Solution() : parentNode(100005, 0), nodeDepth(100005, 0), nodeMap(100005, nullptr) {}

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int dummy = depthFirstSearch(root);
        vector<int> result;

        for (auto& query : queries) {
            if (parentNode[query] == 0) {
                result.push_back(0);
                continue;
            }
            int current = query;
            int depthDiff = 0;
            
            while (parentNode[current]) {
                TreeNode* tempNode = nodeMap[parentNode[current]];
                int leftValue = 0, rightValue = 0;
                if (tempNode->left) {
                    leftValue = nodeDepth[tempNode->left->val];
                }
                if (tempNode->right) {
                    rightValue = nodeDepth[tempNode->right->val];
                }

                if (tempNode->left && tempNode->left->val == current) {
                    depthDiff = max(rightValue, depthDiff);
                } else if (tempNode->right && tempNode->right->val == current) {
                    depthDiff = max(leftValue, depthDiff);
                }

                depthDiff++;
                current = tempNode->val;
            }
            depthDiff--;
            result.push_back(depthDiff);
        }

        return result;
    }
};
