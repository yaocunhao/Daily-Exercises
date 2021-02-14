//给定一个二叉树，计算 整个树 的坡度 。一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
//如果没有左子树的话，左子树的节点之和为 0 没有右子树的话也是一样。空结点的坡度是 0 。整个树 的坡度就是其所有节点的坡度之和。


//通过后续遍历的办法计算二叉树的坡度

int traverse(struct TreeNode *root, int *tilt)
{
	int l, r;
	if (root)
	{
		l = traverse(root->left, tilt);     //左子树和
		r = traverse(root->right, tilt);    //右子树和
		*tilt += abs(l - r);        //求坡度
		return l + r + root->val;
	}
	return 0;
}

int findTilt(struct TreeNode *root)
{
	int tilt = 0;
	traverse(root, &tilt);
	return tilt;
}
