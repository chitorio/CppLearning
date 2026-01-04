#include <bits/stdc++.h>
using namespace std;

// 调整堆，使其满足最大堆性质
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // 初始化最大元素为根节点
    int left = 2 * i + 1;   // 左子节点
    int right = 2 * i + 2;  // 右子节点

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点比当前最大节点大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大元素不是根节点
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // 递归调整受影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序主函数
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 逐个从堆中提取元素
    for (int i = n - 1; i > 0; i--) {
        // 将当前根节点（最大值）移动到数组末尾
        swap(arr[0], arr[i]);
        // 调整剩余堆
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr);

    // 输出排序结果
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}