#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    getline(cin, s);  // 读取主串
    getline(cin, t);  // 读取模式串
    
    // 使用string的find函数
    size_t pos = s.find(t);
    
    // 如果找到，输出位置；否则输出-1
    if (pos != string::npos) {
        cout << pos << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}