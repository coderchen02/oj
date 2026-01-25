//2026.1.25 20点11分
class Solution {
public:
    int pre=0;//记录前一个节点的数值
    void traversal(TreeNode* cur){
        if(!cur) return;
    traversal(cur->right);
    cur->val+=pre;
    pre=cur->val;
    traversal(cur->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        pre=0;
        traversal(root);
        return root;
    }
};