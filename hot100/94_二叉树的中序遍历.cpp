//2026.1.24 19点08分
class Solution {
public:
    void traversal(TreeNode* cur,vector<int>& vec){
        if(cur==NULL) return ;
        traversal(cur->left,vec);
        vec.push_back(cur->val);
        traversal(cur->right,vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root,ans);
        return ans;
    }
};