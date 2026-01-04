#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;  // 栈的最大容量

int main() {
    int stack[MAX_SIZE];  // 用数组模拟栈
    int top = -1;         // 栈顶指针，-1表示空栈
    
    int operation;
    
    // 循环读取操作
    while (cin >> operation && operation != -1) {
        if (operation == 1) {
            // 入栈操作
            int value;
            cin >> value;
            
            // 检查栈是否已满
            if (top >= MAX_SIZE - 1) {
                cout << "error ";
            } else {
                top++;
                stack[top] = value;
            }
        } 
        else if (operation == 0) {
            // 出栈操作
            if (top == -1) {
                // 栈空，输出错误
                cout << "error ";
            } else {
                // 输出栈顶元素
                cout << stack[top] << " ";
                top--;  // 出栈
            }
        }
    }
    
    return 0;
}