// 2026.1.20 21点07分
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        //前序遍历进行交换 此题不可以用中序遍历 因为会导致翻转两遍 具体可以找个例子手动模拟一下
        swap(root->left,root->right); //根节点
        invertTree(root->left);    //左子树
        invertTree(root->right);   //右子树
        return root;
    }
};