class Solution {
public:
    void _findSecondMinimumValue(TreeNode*root,int &one,int &two)
    {
        if(root==nullptr)
            return ;
        int val=root->val;
        if(val<one)
        {
            swap(one,two);
            one=val;
        }
        else if((val<two&&val!=one) || one==two)
            two=val;


        _findSecondMinimumValue(root->left,one,two);
        _findSecondMinimumValue(root->right,one,two);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int one=root->val;
        int two=root->val;
        _findSecondMinimumValue(root,one,two);

        if(one==two)
            return -1;

        return two;
    }
};