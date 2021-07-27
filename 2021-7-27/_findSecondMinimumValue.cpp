class Solution {
public:
    void _findSecondMinimumValue(TreeNode*root,int &val,int &ans)
    {
        if(root==nullptr)
            return ;

        if(root->val > val && (root->val < ans || ans==-1))
            ans=root->val;

        _findSecondMinimumValue(root->left,val,ans);
        _findSecondMinimumValue(root->right,val,ans);
    }
    int findSecondMinimumValue(TreeNode* root) {
        //根节点是最小节点

        
        int val=root->val;
        int ans=-1;

        _findSecondMinimumValue(root,val,ans);
        return ans;
    }
};