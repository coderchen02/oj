// 2026.1.25 22点37分
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        vector<TreeNode*> path_p;
        vector<TreeNode*> path_q;
        dfs(root,p,q,path,path_p,path_q);
        TreeNode* ans=NULL;
        for(int i=0;i<path_p.size()&&i<path_q.size();i++)
            if(path_p[i]==path_q[i]) ans=path_p[i];
            else break;
        return ans;

    }
    void dfs(TreeNode* node,TreeNode* p,TreeNode* q,vector<TreeNode*>& path,vector<TreeNode*>& path_p,
        vector<TreeNode*>& path_q){
            if(!node||(!path_p.empty()&&!path_q.empty())) return ;//node为空||(p的路径已找到||q的路径已找到）
                path.push_back(node);
                if(node==p)
                    path_p=path;
                if(node==q)
                    path_q=path;
                if(path_p.empty()||path_q.empty()){
                    dfs(node->left,p,q,path,path_p,path_q);
                    dfs(node->right,p,q,path,path_p,path_q);
                }
                path.pop_back();
        }
};