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

    //记录每个节点的父亲节点
    void RecordParetn(TreeNode* root,unordered_map<int,TreeNode*>&record)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            record[root->left->val]=root;
            RecordParetn(root->left,record);
        }
        if(root->right)
        {
            record[root->right->val]=root;
            RecordParetn(root->right,record);
        }
    }


    void Find(TreeNode*root,int k,int depth,vector<int>&ret,TreeNode* from,unordered_map<int,TreeNode*>&record)
    {
        if(root==NULL)
            return;
        if(k==depth)
        {
            ret.push_back(root->val);
            return;
        }
        
        if(root->left!=from)
            Find(root->left,k,depth+1,ret,root,record);
        if(root->right!=from)
            Find(root->right,k,depth+1,ret,root,record);
        if(record[root->val]!=from)
            Find(record[root->val],k,depth+1,ret,root,record);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //用哈希表记录每个节点的父亲
        unordered_map<int,TreeNode*> record;
        RecordParetn(root,record);

        //从target开始进行寻找
        vector<int> ret;
        Find(target,k,0,ret,nullptr,record);

        return ret;
    }
};