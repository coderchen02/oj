// 3.2 21点41分
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    // 长度为2的数组 0：不偷 1：偷
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur,那么就不能偷左右节点
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur 那么可以偷也可以不偷左右节点，则取较大的情况
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};