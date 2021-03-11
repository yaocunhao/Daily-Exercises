//Æ½ºâ¶þ²æÊ÷

int GetHight(struct TreeNode *root)
{
	if (root == NULL)
		return 0;

	int left = 1 + GetHight(root->left);
	int right = 1 + GetHight(root->right);

	return left>right ? left : right;
}
bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;

	int left = GetHight(root->left);
	int right = GetHight(root->right);
	int lable = abs(left - right);

	return lable<2 && isBalanced(root->left) && isBalanced(root->right);

}

//¾µÏñ¶þ²æÊ÷
bool Judge(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL&&right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return
		(left->val == right->val) &&
		Judge(left->left, right->right) &&
		Judge(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;

	return Judge(root->left, root->right);
}