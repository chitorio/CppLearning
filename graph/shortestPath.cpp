#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    vector<string> lines;
    string line;
    
    // 读取图的邻接矩阵
    while (getline(cin, line) && !line.empty()) {
        lines.push_back(line);
    }
    
    int n = lines.size() - 1;  // 最后一行是起点终点
    
    // 解析邻接矩阵
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        stringstream ss(lines[i]);
        for (int j = 0; j < n; j++) {
            string val;
            ss >> val;
            if (val == "-1") {
                graph[i][j] = INF;  // 没有连接
            } else {
                graph[i][j] = stoi(val);
            }
        }
    }
    
    // 解析起点和终点
    string startEnd = lines[n];
    stringstream ss(startEnd);
    char startChar, endChar;
    ss >> startChar >> endChar;
    
    // 转换为索引（A=0, B=1, C=2, ...）
    int start = startChar - 'A';
    int end = endChar - 'A';
    
    // Dijkstra算法
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    
    dist[start] = 0;
    
    for (int i = 0; i < n; i++) {
        // 找到未访问节点中距离最小的
        int u = -1;
        int minDist = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        
        if (u == -1 || u == end) break;  // 所有节点已访问或已找到终点
        
        visited[u] = true;
        
        // 更新邻居距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    
    cout << dist[end] << endl;
    
    return 0;
}