#include <bits/stdc++.h>
using namespace std;

// 并查集实现
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) {
        parent.resize(n + 1);  // 节点编号从1开始
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;  // 每个节点初始时是自己的父节点
        }
    }
    
    // 查找根节点（路径压缩）
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }
    
    // 合并两个集合（按秩合并）
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false;  // 已经在同一个集合中
        }
        
        // 按秩合并
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

// 边结构体
struct Edge {
    int u, v, weight;
    
    // 重载<运算符，用于排序
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int main() {
    int n, count;
    cin >> n >> count;
    
    // 存储所有边
    vector<Edge> edges(count);
    
    // 读取边
    for (int i = 0; i < count; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    // Kruskal算法
    // 1. 按权重排序边
    sort(edges.begin(), edges.end());
    
    // 2. 初始化并查集
    UnionFind uf(n);
    
    // 3. 遍历边，构建最小生成树
    int mstWeight = 0;  // 最小生成树的总权重
    int edgesUsed = 0;  // 已使用的边数
    
    for (const Edge& edge : edges) {
        // 如果这条边连接的两个节点不在同一个连通分量中
        if (uf.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesUsed++;
            
            // 最小生成树有n-1条边
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }
    
    cout << mstWeight << endl;
    
    return 0;
}