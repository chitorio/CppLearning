#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    char start;
    cin >> n >> start;

    // 跳过换行符
    cin.ignore();

    // 使用邻接图存储图
    unordered_map<char, vector<char>> graph;

    // 读取图的数据
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        // 解析每一行
        char node = line[0];

        // 找到冒号后的左花括号
        size_t brace_pos = line.find('{');
        if (brace_pos == string::npos) continue;

        // 提取花括号内的内容
        string connections = line.substr(brace_pos + 1);
        connections.pop_back(); // 移除最后的'}'

        // 解析邻接节点
        stringstream ss(connections);
        string token;

        while (getline(ss, token, ',')) {
            // 移除空格
            token.erase(remove(token.begin(), token.end(), ' '), token.end());

            if (!token.empty()) {
                char neighbor = token[0];
                graph[node].push_back(neighbor);
            }
        }
    }

    // BFS遍历
    queue<char> q;
    unordered_set<char> visited;
    vector<char> result;

    // 从起始节点开始
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char current = q.front();
        q.pop();
        result.push_back(current);

        // 遍历当前节点的所有邻接节点
        for (char neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    // 输出结果
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}