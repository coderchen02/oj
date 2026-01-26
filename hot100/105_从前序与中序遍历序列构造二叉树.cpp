// 2026.1.26 17点56分
class Solution {
public:
    unordered_map<int, int> pos; // 记录中序序列的数值和相对位置
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int pl,int pr,int il,int ir){
        if(pl>pr||il>ir) return nullptr;
        //找到左子树的节点个数
        int k=pos[preorder[pl]]-il;
        //在中序序列中找到根节点
        TreeNode* node=new TreeNode(preorder[pl]);
        node->left=build(preorder,inorder,pl+1,pl+k,il,il+k-1);
        node->right=build(preorder,inorder,pl+k+1,pr,il+k+1,ir);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
    return build(preorder,inorder,0,inorder.size()-1,0,inorder.size()-1);
    }
};