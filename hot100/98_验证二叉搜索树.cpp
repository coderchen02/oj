//3.9 22点31分
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long pre_val=LONG_MIN;
        return help(root,pre_val);
    }
    bool help(TreeNode* root,long long & pre_val){
        if(!root) return true;
        if(!help(root->left,pre_val)) return false;
        if(root->val<=pre_val) return false;
        pre_val=root->val;
        if(!help(root->right,pre_val)) return false;
        return true;
    }
};