//2026.1.24 19点28分
class Solution {
public:
    bool check(TreeNode*left,TreeNode*right){
        //排除空节点的情况
        if(left==NULL&&right!=NULL) return false;
        if(left!=NULL&&right==NULL) return false;
        if(left==NULL&&right==NULL) return true;
        if(left->val!=right->val) return false;
        //此时就是：左右节点都不为空，且数值相同的情况
        //此时才做递归。做下一层判断
        bool outside=check(left->left,right->right);//左子树的：左 右子树的：右
        bool inside=check(left->right,right->left);//左子树的：右 右子树的：左
        return outside&&inside;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root->left,root->right);
    }
};