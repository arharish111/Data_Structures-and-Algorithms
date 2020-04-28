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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;
        dfs(root1,r1);
        dfs(root2,r2);
        if(r1.size()!=r2.size())
            return false;
        for(int i=0;i<r1.size();i++)
        {
            if(r1[i]!=r2[i])
                return false;
        }
        return true;
    }
    
    void dfs(TreeNode* r,vector<int>& r1)
    {
        if(r==NULL)
            return;
        if(r->left==NULL && r->right==NULL)
        {
            r1.push_back(r->val);
        }
        dfs(r->left,r1);
        dfs(r->right,r1);
    }
};