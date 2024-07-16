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
    string st, dt;
    
    void dfs(TreeNode* par, int s, int d, string &tmp) {
        if (!par) return;
        
        if (par->val == s) {
            st = tmp;
        }
        
        if (par->val == d) {
            dt = tmp;
        }
        
        tmp += 'L';
        dfs(par->left, s, d, tmp);
        tmp.pop_back();
        
        tmp += 'R';
        dfs(par->right, s, d, tmp);
        tmp.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string str;
        dfs(root, startValue, destValue, str);
        string ret = "";
        
        reverse(st.begin(), st.end());
        reverse(dt.begin(), dt.end());
        
        cout << st << endl << dt << endl;
        
        while (!st.empty() && !dt.empty()) {
            if (st.back() == dt.back()) {
                st.pop_back();
                dt.pop_back();
            } else {
                break;
            }
        }
        
        while (!st.empty()) {
            ret.push_back('U');
            st.pop_back();
        }
        
        while (!dt.empty()) {
            char ch = dt.back();
            ret.push_back(ch);
            dt.pop_back();
        }
        
        return ret;
    }
};
