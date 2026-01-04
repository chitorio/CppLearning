#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    
    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    
    // 散列表，初始化为-1表示空
    vector<int> hashTable(m, -1);
    // 探查次数表
    vector<int> probeCount(m, 0);
    
    // 插入每个键
    for (int i = 0; i < n; i++) {
        int key = keys[i];
        int hashIndex = key % p;
        int probe = 1;  // 探查次数，从1开始
        
        // 线性探测
        int index = hashIndex;
        while (hashTable[index] != -1) {
            probe++;
            index = (index + 1) % m;
        }
        
        // 找到空位，插入键值
        hashTable[index] = key;
        probeCount[index] = probe;
    }
    
    // 输出第一行：地址序列
    for (int i = 0; i < m; i++) {
        cout << i;
        if (i < m - 1) cout << " ";
    }
    cout << endl;
    
    // 输出第二行：散列表内容
    for (int i = 0; i < m; i++) {
        cout << hashTable[i];
        if (i < m - 1) cout << " ";
    }
    cout << endl;
    
    // 输出第三行：探查次数
    for (int i = 0; i < m; i++) {
        cout << probeCount[i];
        if (i < m - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}