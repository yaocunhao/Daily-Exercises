合并二叉树

class Solution {
public:
    void  _mergeTrees(TreeNode** root1, TreeNode** root2) {
        if(*root1==NULL&&*root2==NULL)
            return ;
        if(*root1==NULL)
        {
            *root1=*root2;
            return ;
        }
        if(*root2==NULL)
            return ;
        
        (*root1)->val+=(*root2)->val;

        _mergeTrees(&((*root1)->left),&((*root2)->left));
        _mergeTrees(&((*root1)->right),&((*root2)->right));
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        _mergeTrees(&root1,&root2);
        return root1;        
    }
};