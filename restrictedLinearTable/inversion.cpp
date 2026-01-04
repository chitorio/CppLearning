#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<int> q;
    
    // 读取元素并入队
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    // 创建空栈
    stack<int> s;
    
    // 第一步：队列Q中的所有元素出队，压入栈S
    while (!q.empty()) {
        s.push(q.front());  // 获取队首元素
        q.pop();            // 队首元素出队
    }
    
    // 第二步：栈S中的所有元素弹出，压入队列Q
    while (!s.empty()) {
        q.push(s.top());    // 获取栈顶元素
        s.pop();            // 弹出栈顶元素
    }
    
    // 输出逆置后的队列
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    return 0;
}