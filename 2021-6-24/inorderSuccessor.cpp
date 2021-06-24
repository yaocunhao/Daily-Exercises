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
    void _inorderSuccessor(TreeNode* root,TreeNode* p,int &flag,TreeNode* &ret)
    {
        if(root==NULL||ret!=NULL)
            return ;
        
        _inorderSuccessor(root->left,p,flag,ret);

       if(ret!=NULL)
           return;

        if(flag==1)
        {
            ret=root;
            return ;
        }

        if(root==p)
            flag=1;
        _inorderSuccessor(root->right,p,flag,ret);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ret=NULL;
        int flag=0;

        _inorderSuccessor(root,p,flag,ret);
        return ret;
    }
};