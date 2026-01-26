// 2026.1.26 21点07分
class Solution {
public:
    unordered_map<int,int> pos;//记录中序序列的位置和数值的对应关系
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int il,int ir,int pl,int pr){
        if(il>ir||pl>pr) return nullptr;
        int k=pos[postorder[pr]]-il; //找到左子树的个数
        TreeNode* root=new TreeNode(postorder[pr]);
        root->left=build(inorder,postorder,il,il+k-1,pl,pl+k-1);
        root->right=build(inorder,postorder,il+k+1,ir,pl+k,pr-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++) pos[inorder[i]]=i;
        return build(inorder,postorder,0,n-1,0,n-1);
    }
};