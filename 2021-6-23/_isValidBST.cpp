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
    bool _isValidBST(TreeNode* root,int &min,TreeNode* lt)
    {
        if(root==NULL)
            return true;
        
        bool left=_isValidBST(root->left,min,lt);
        if(root->val<=min&&root!=lt)
            return false;
        //更新min
            min=root->val;

        bool right=_isValidBST(root->right,min,lt);

        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return  true;

        TreeNode* min=root;
        while(min->left)
        {
            min=min->left;
        }

        int first=min->val;//得到中序遍历的第一个值   
        TreeNode* lt=min;
        return _isValidBST(root,first,lt);
    }
};