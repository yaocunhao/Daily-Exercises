class Solution {
public:
    void  _convertBST(TreeNode* root,int &prev)
    {
        if(root==nullptr)
            return;

        _convertBST(root->right,prev);
        root->val+=prev;
        prev=root->val;
        _convertBST(root->left,prev); 
    }
    TreeNode* convertBST(TreeNode* root) {
        int prev=0;
        _convertBST(root,prev);
        return root;
    }
};