// 3.12 21点39分
class Solution {
private:
    // 父节点哈希表：key=变量，value=父节点
    unordered_map<string, string> parent;
    // 权重哈希表：key=变量，value=该变量/父节点的比值
    unordered_map<string, double> weight;

    // 查找根节点 + 路径压缩
    string find(const string& x) {
        // 若x不在parent中，说明未初始化（查询时直接返回-1）
        if (!parent.count(x)) return "";
        // 路径压缩：递归找到根节点，同时更新当前节点的权重
        if (parent[x] != x) {
            string origin_parent = parent[x];  // 保存x的原始父节点（压缩前的父节点）
            // 递归查找原始父节点的根节点（最终找到整个集合的根）
            string root = find(parent[x]);
           // 路径压缩：将x直接挂到根节点下（跳过中间节点，优化后续查找）
            parent[x] = root;
            // 权重更新：x/root = (x/origin_parent) * (origin_parent/root)
            // 对应公式：weight[x]（新）= weight[x]（旧） * weight[origin_parent]
            weight[x] *= weight[origin_parent];
        }
        return parent[x];   // 返回x的根节点
    }

    // 初始化变量
    void init(const string& x) {
        if (!parent.count(x)) { // 仅当x未初始化时执行
            parent[x] = x;      // 初始时，变量的父节点是自身（根节点）
            weight[x] = 1.0;       // 初始权重=1.0（因为x/x=1）
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1. 初始化并合并所有等式
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double k = values[i]; // a/b = k → a = b*k
            // 初始化a和b（确保变量在parent/weight中存在）
            init(a);
            init(b);
            // 找到a和b的根节点 （查找时自动路径压缩）
            string root_a = find(a);
            string root_b = find(b);
            // 合并：将root_a挂到root_b下
            if (root_a != root_b) {
                parent[root_a] = root_b;
            // 推导root_a的权重：核心数学公式！
            // 已知：a/root_a = weight[a] --> a = root_a * weight[a]
            // 已知：b/root_b = weight[b] -→ b = root_b * weight[b]
            // 已知：a/b = k -→ (root_a * weight[a]) / (root_b * weight[b]) = k
            // 变形得：root_a/root_b = k * weight[b] / weight[a]
            // 而weight[root_a] = root_a / parent[root_a] = root_a / root_b
            // 因此：weight[root_a] = k * weight[b] / weight[a]
                weight[root_a] = k * weight[b] / weight[a];
            }
        }

        // 2. 处理所有查询
        vector<double> res;
        for (auto& q : queries) {
            string x = q[0];    // 查询的分子（如"a"）
            string y = q[1];    // 查询的分母（如"c"）
            // 若x或y未初始化，直接返回-1
            if (!parent.count(x) || !parent.count(y)) {
                res.push_back(-1.0);
                continue;
            }
            // 找到x和y的根节点（查找时自动路径压缩）
            string root_x = find(x);
            string root_y = find(y);
            // 根节点不同 → x和y无连通关系，无法推导比值
            if (root_x != root_y) {
                res.push_back(-1.0);
            } else {
                // 根节点相同：x/y = (x/root) / (y/root) = weight[x]/weight[y]
                res.push_back(weight[x] / weight[y]);
            }
        }
        return res;
    }
};