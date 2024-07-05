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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool ltr=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> row(s);
            for(int i=0;i<s;i++){
                TreeNode* thisnode=q.front();
                q.pop();
                int idx=ltr?i:(s-i-1);
                row[idx]=thisnode->val;
                if(thisnode->left) q.push(thisnode->left);
                if(thisnode->right) q.push(thisnode->right);
            }
            ltr=!ltr;
            ans.push_back(row);
        }
        return ans;
    }
};