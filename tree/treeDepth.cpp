#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构建二叉树（层序）
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "None") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q; // 待处理节点
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();  // 当前要处理的父节点
        q.pop();

        // 左孩子
        if (i < nodes.size() && nodes[i] != "None") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;
        
        // 右孩子
        if (i < nodes.size() && nodes[i] != "None") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

// 求最大深度
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    vector<string> nodes;
    string line;

    // 读取一行数据
    getline(cin, line);
    stringstream ss(line);
    string s;
    while (ss >> s) {
        nodes.push_back(s);
    }

    TreeNode* root = buildTree(nodes);
    cout << maxDepth(root) << endl;

    return 0;
}
