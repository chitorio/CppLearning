#include <bits/stdc++.h>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);
    
    stack<char> s;
    
    for (char ch : expr) {
        // 如果是左括号，入栈
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // 如果是右括号，检查匹配
        else if (ch == ')' || ch == ']' || ch == '}') {
            // 如果栈为空，说明右括号多余
            if (s.empty()) {
                cout << 0 << endl;
                return 0;
            }
            
            char top = s.top();
            s.pop();
            
            // 检查括号是否匹配
            if (ch == ')' && top != '(') {
                cout << 0 << endl;
                return 0;
            }
            if (ch == ']' && top != '[') {
                cout << 0 << endl;
                return 0;
            }
            if (ch == '}' && top != '{') {
                cout << 0 << endl;
                return 0;
            }
        }
        // 其他字符（数字、运算符等）忽略
    }
    
    // 如果栈不为空，说明左括号多余
    cout << (s.empty() ? 1 : 0) << endl;
    
    return 0;
}