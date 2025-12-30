#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // 读取正整数加入优先队列
    for (int i = 0; i < n; i++) {
        int weight;     // 权重
        cin >> weight;
        minHeap.push(weight);
    }

    int totalWeight = 0;    // 带权路径长度

    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        // 取出最小的两个节点
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // 合并
        int merged = first + second;

        minHeap.push(merged);

        totalWeight += merged;
    }

    cout << totalWeight << endl;

    return 0;
}