 二叉树的镜像

class Solution {
    stack<TreeNode*> st;
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL)
        return root;

        st.push(root);

        while(!st.empty())
        {
            TreeNode *root=st.top();
            st.pop();
            swap(root->left,root->right);
             if(root->right!=NULL)
                st.push(root->right);
            if(root->left!=NULL)
                st.push(root->left);
        }
        return root;

    }
};