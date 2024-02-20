class Solution {
public:
 vector<vector<int>> levelOrderBottom(TreeNode* root) 
 {
       vector<vector<int>> ans;
       stack<vector<int>> st;
       vector<int> v;

       if(root == NULL)
       return ans;

       queue<TreeNode*> q;
       q.push(root);
       q.push(NULL);

    while(!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
           //matlab ek level complete ho gya hai
       
           if(!q.empty())
           {
               // matlab aur child nodes hai abhi
               q.push(NULL);
               st.push(v);
               v.resize(0);
           }

        }

        else
        {
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }

            v.push_back(temp->val);
        }

    }

    st.push(v);

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
        
    }
};