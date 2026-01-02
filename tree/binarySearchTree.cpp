#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 逐点插入法构造BST
TreeNode* insertBST(TreeNode* root, int val, int& depth, int currDepth) {
    if (!root) {
        depth = max(depth, currDepth);  // 更新最大深度
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insertBST(root->left, val, depth, currDepth + 1);
    } else {
        root->right = insertBST(root->right, val, depth, currDepth + 1);
    }
    return root;
}

// 中序遍历并收集结果
void inorderTraversal(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorderTraversal(root->left, res); // 先遍历左子树
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;
    int maxDepth = 0;   // 记录最大深度

    // 构建BST
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val, maxDepth, 1);
    }

    // 输出层数
    cout << maxDepth << endl;

    // 中序遍历和输出
    vector<int> inorder;
    inorderTraversal(root, inorder);
    for (size_t i = 0; i < inorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << inorder[i];
    }
    cout << endl;

    return 0;
}