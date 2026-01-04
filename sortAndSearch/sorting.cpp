#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    int num;
    
    // 读取第一行：整数数组
    string line;
    getline(cin, line);
    stringstream ss(line);
    
    while (ss >> num) {
        nums.push_back(num);
    }
    
    // 读取第二行：k
    int k;
    cin >> k;
    
    // 对整个数组排序
    sort(nums.begin(), nums.end());
    
    // 输出前k个最小的数
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}