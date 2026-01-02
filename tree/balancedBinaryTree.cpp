#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 从层序遍历数组构建二叉树
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "None") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        // 左子节点
        if (i < nodes.size() && nodes[i] != "None") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;
        // 右子节点
        if (i < nodes.size() && nodes[i] != "None") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// 计算树的高度，若不平衡返回-1
int checkHeight(TreeNode* root) {
    if (!root) return 0;
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

// 判断是否平衡
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    vector<string> nodes;
    string s;
    while (cin >> s) {
        nodes.push_back(s);
    }
    TreeNode* root = buildTree(nodes);
    if (isBalanced(root)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}