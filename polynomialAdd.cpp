#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;

// 定义结构体Node
struct Node {
    double coef;
    int exp;
    Node* next;
    Node(double c, int e): coef(c), exp(e), next(nullptr) {}
};

// 链表尾部插入结点
void append(Node*& head, double coef, int exp) {
    Node* newNode = new Node(coef, exp);
    if (!head) {
        head = newNode;     //创建头
    } else {
        Node* p = head;
        while (p->next) {
            p = p->next;
        }
        p->next = newNode;
    }
}

// 合并两个多项式，返回result链表头
Node* addPloy(Node* A, Node* B) {
    Node* result = nullptr;  // 初始化result

    // 把A拷贝进result
    for (Node* p = A; p; p = p->next) {
        append(result, p->coef, p->exp);
    }

    // 把B合并到result
    for (Node* q = B; q; q = q->next) {
        Node* p = result;
        bool found = false;     // 定义found来判断是否添加
        while (p) {
            if (p->exp == q->exp) {
                p->coef += q->coef;
                found = true;
                break;
            }
            p = p->next;
        }
        if (!found) append(result, q->coef, q->exp);
    }
    
    // 删除系数为0的项
    Node* prev = nullptr;   // 前驱结点
    Node* cur = result;    // current
    while (cur) {
        if (abs(cur->coef) < 1e-9) {    // 认为系数是0
            if (!prev) {    // 前驱结点不存在，即cur指向链表头
                result = cur->next;
                delete cur; // 删除指向内存，不删除指针本身
                cur = result;
            } else {        // cur指向中间
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
        } else {    // cur系数不为0，两者都向后一步
            prev = cur;
            cur = cur->next;
        }
    }

    // 选择排序（降序）
    for (Node* p = result; p; p = p->next) {
        for (Node* q = p->next; q; q = q->next) {
            if (p->exp < q->exp) {
                swap(p->exp, q->exp);
                swap(p->coef, q->coef);
            }
        }
    }

    return result;
}

int main() {
    string line;
    Node* A = nullptr;
    Node* B = nullptr;

    // 读第一行
    getline(cin, line);
    stringstream ss1(line);
    double c; int e;
    while (ss1 >> c >> e) {     // 自动忽略空格
        append(A, c, e);
    }

    // 读第二行
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> c >> e) {     // 自动忽略空格
        append(B, c, e);
    }

    // 读第三行k
    int k;
    cin >> k;

    // 多项式相加
    Node* result = addPloy(A, B);

    // 找第k项
    Node* p = result;
    int count = 1;
    while (p && count < k) {
        p = p->next;
        count++;
    }

    cout << fixed << setprecision(1) << p->coef << " " << p->exp << endl;

    return 0;
}