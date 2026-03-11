//3.11 22点06分
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        int height=0;
        dfs(root,res,height);
        return res;
    }
    void dfs(TreeNode* topNode,int& res,int & topNodeHeight){//参数:当前的顶点 结果 以当前节点为根节点的二叉树的高度
        if(!topNode){
            topNodeHeight=0;
            return;
        }
        int leftHeight=0;
        dfs(topNode->left,res,leftHeight);
        int rightHeight=0;
        dfs(topNode->right,res,rightHeight);
        res=max(res,leftHeight+rightHeight);
        topNodeHeight=max(leftHeight,rightHeight)+1;
    }
};