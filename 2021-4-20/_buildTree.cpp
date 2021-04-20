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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int &pre_sub,int in_begin,int in_end) 
    {
        if(in_begin>in_end)
        return NULL;

        TreeNode *root=new TreeNode(preorder[pre_sub]);//构建根节点
        int index=in_begin;

        while(index<=in_end)//在中序中找根节点
        {
            if(preorder[pre_sub]==inorder[index])
                break;
            else
            index++;
        }
        //在中序中找到根节点

        if(in_begin<=index-1)//表示可以在区间找到
        root->left=_buildTree(preorder,inorder,++pre_sub,in_begin,index-1);//左子树
        else
        root->left=NULL;//没有找到

        if(index+1<=in_end)
        root->right=_buildTree(preorder,inorder,++pre_sub,index+1,in_end);//右子树
        else
        root->right=NULL;//没有找到

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
      int pre_sub=0;
      return _buildTree(preorder,inorder,pre_sub,0,inorder.size()-1);
    }
};