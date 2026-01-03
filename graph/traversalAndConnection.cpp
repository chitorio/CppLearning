#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 读取邻接矩阵
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    // 记录节点是否被访问过
    vector<bool> visited(n, false);
    int components = 0;  // 连通分量计数器
    
    // 对每个节点进行BFS遍历
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // 发现一个新的连通分量
            components++;
            
            // BFS遍历当前连通分量
            queue<int> q;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                // 遍历所有邻接节点
                for (int neighbor = 0; neighbor < n; neighbor++) {
                    // 如果有边且邻居未访问过
                    if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    
    cout << components << endl;
    return 0;
}