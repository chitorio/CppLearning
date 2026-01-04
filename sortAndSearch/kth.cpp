#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 创建最小堆（优先队列默认是最大堆，所以要自定义比较函数）
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    // 遍历数组
    for (int num : nums) {
        if (minHeap.size() < k) {
            // 堆中元素不足k个，直接加入
            minHeap.push(num);
        } else {
            // 堆已满，如果当前元素比堆顶大，替换堆顶
            if (num > minHeap.top()) {
                minHeap.pop();
                minHeap.push(num);
            }
        }
    }
    
    // 堆顶就是第K大的元素
    cout << minHeap.top() << endl;
    
    return 0;
}