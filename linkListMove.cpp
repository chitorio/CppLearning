// 祥，移动
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <utility>

using namespace std;

struct node {
    int data;
    node* next;
};

// 建立链表
void append(node*& head, int data) {
    node* newNode = new node{data, nullptr};
    if (!head) {
        head = newNode;
    } else {
        node* p = head;
        while (p->next) p = p->next;
        p->next = newNode;
    }
}

// 选择+移动
void sakimove(node*& head) {
    node* saki = head;
    node* presaki = nullptr;
    node* p = head;
    node* prev = nullptr;

    while (p) {
        if (p->data > saki->data) {
            saki = p;
            presaki = prev;
        }
        prev = p;
        p = p->next;
    }

    if (saki->next == nullptr) return;  // 已经在尾部

    // 断开saki酱
    if (presaki == nullptr) {
        head = head->next;
    } else {
        presaki->next = saki->next;
    }

    // 移动到尾部
    node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = saki;
    saki->next = nullptr;
}

int main() {
    int data;
    node* head = nullptr;
    while (cin >> data) {
        append(head, data);
    }
    sakimove(head);
    for (node* p = head; p; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " ";
    }
    cout << endl;

    return 0;
}