// 2583. Kth Largest Sum in a Binary Tree
// cpp Solution
// Basic graph traversal problem


#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> nodeQueue;  // Queue to store tree nodes level by level
        nodeQueue.push(root);
        vector<ll> levelSums;  // To store sums of each level
        ll currentLevelSum;  // Sum of the current level
        TreeNode* currentNode;
        int currentLevelSize;  // Number of nodes in the current level

        while (!nodeQueue.empty()) {
            currentLevelSize = nodeQueue.size();
            currentLevelSum = 0;

            while (currentLevelSize) {
                currentNode = nodeQueue.front();
                nodeQueue.pop();
                currentLevelSum += currentNode->val;
                currentLevelSize--;

                if (currentNode->left != nullptr) nodeQueue.push(currentNode->left);
                if (currentNode->right != nullptr) nodeQueue.push(currentNode->right);
            }

            levelSums.push_back(currentLevelSum);  // Store the sum of this level
        }

        if (levelSums.size() < k) return -1;  // If less than k levels exist

        sort(levelSums.begin(), levelSums.end(), greater<ll>());  // Sort in descending order
        return levelSums[k - 1];  // Return the kth largest level sum
    }
};
