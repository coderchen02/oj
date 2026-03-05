// 3.4 20点31分
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int total = 0;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            total += dfs(node, 0, targetSum);
            if (node) {
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        return total;
    }
        int dfs(TreeNode * node, long long cur_sum, int targetSum) {
            if (!node)
                return 0;
            cur_sum += node->val;
            int count = 0;
            if (cur_sum == targetSum)
                count++;
            count += dfs(node->left, cur_sum, targetSum);
            count += dfs(node->right, cur_sum, targetSum);
            return count;
        }
};