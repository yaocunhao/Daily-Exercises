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


    void CountNumber(TreeNode* root,int val,int targetSum,int &count)
    {
        if(root==nullptr)
            return;
        
        val+=root->val;

        if(val==targetSum)
            count++;

        CountNumber(root->left,val,targetSum,count);
        CountNumber(root->right,val,targetSum,count);
    }
    void _pathSum(TreeNode* root,int targetSum,int &count)
    {
        if(root==nullptr)
            return;

        CountNumber(root,0,targetSum,count);//以当前节点为根节点进行前序遍历
        
        _pathSum(root->left,targetSum,count);
        _pathSum(root->right,targetSum,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        //以每一个节点为根节点进行遍历即可
        int count=0;
        _pathSum(root,targetSum,count);//以每一个节点为根节
        return count;
    }
};