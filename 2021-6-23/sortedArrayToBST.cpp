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
    TreeNode* _sortedArrayToBST(vector<int>& nums,int begin,int end)
    {
        if(begin>end)
            return NULL;
        
        int mid=begin+(end-begin)/2;//确定中心点
        
        TreeNode* root = new TreeNode(nums[mid]);//创建根节点
        
        //创建子树
        root->left=_sortedArrayToBST(nums,begin,mid-1);
        root->right=_sortedArrayToBST(nums,mid+1,end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //高度最小，每一层都摆满
        //找到中心点为根，然后再从左右之中寻找中心点作为根节点

        int begin=0;
        int end=nums.size()-1;

        return _sortedArrayToBST(nums,begin,end);
    }
};