// 3.3 20点24分
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize_help(root, res);
        return res;
    }
    void serialize_help(TreeNode* root, string& res) {
        if (!root) { // 如果遇到空
            if (res.size() == 0) {
                res += "N";
                return;
            } else {
                res += ",N";
                return;
            }
        }
        if (res.size() == 0)
            res += to_string(root->val);
        else {
            res += ",";
            res += to_string(root->val);
        }
        serialize_help(root->left, res);
        serialize_help(root->right, res);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string tmp;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                nodes.push_back(tmp);
                tmp.clear();
            } else
                tmp += data[i];
        }
        if (tmp.size())
            nodes.push_back(tmp);
        int index = 0;
        return deserialize_help(nodes, index);
    }
    TreeNode* deserialize_help(vector<string>& nodes, int& index) {
        if (nodes[index] == "N") {
            index++;
            return NULL;
        }
        TreeNode* node = new (TreeNode)(stoi(nodes[index]));
        index++;
        node->left = deserialize_help(nodes, index);
        node->right = deserialize_help(nodes, index);
        return node;
    }
};

