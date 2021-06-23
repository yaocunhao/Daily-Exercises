/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        queue<TreeNode*> qe;
        vector<ListNode*> ret;
        if(tree==NULL)
            return ret;
        
        qe.push(tree);
        int size=1;//当前层元素个数
        ListNode *head=NULL;//头结点
        ListNode *cur=NULL;//头结点

        while(!qe.empty())
        {
            TreeNode *node=qe.front();
            qe.pop();
            size--;

        //创建节点
            ListNode* lnode=new ListNode(node->val);
        
        //链表连接
            if(head==NULL)
            {
                head=lnode;
                cur=lnode;
            }
            else
            {
                cur->next=lnode;
                cur=cur->next;
            }

            //左右节点入队
            if(node->left)
                qe.push(node->left);
            if(node->right)
                qe.push(node->right);
            
            if(size==0)//前面一层，已经全部出完
            {
                size=qe.size();
                ret.push_back(head);

                head=NULL;//下一层的头节点
                cur=NULL;
            }
        }
        return ret;
    }
};