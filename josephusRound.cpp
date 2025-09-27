#include <iostream>
#include <iomanip>
using namespace std;

// 单链表结点
struct Node {
    int data;
    Node* next; 
};

// 建立初始链表，M为人数
Node* createList(int M) {
    if (M <= 0) return nullptr;
    Node* head = new Node{1, nullptr};
    Node* tail = head;
    for (int i = 2; i <= M; i++) {
        tail->next = new Node{i, nullptr};
        tail = tail->next;
    }
    tail->next = head;
    return head;
}

// 约瑟夫环一轮，N为报数密码
Node* josephusRound(Node* head, int N, int M) {
    if (!head || N <= 0) {
        return nullptr;
    }

    Node* p = head; // p为要出列的结点
    Node* pre = nullptr;    // p的前一个结点
    Node* newHead = nullptr;
    Node* newTail = nullptr;

    int count = M;  // 当前圈内人数

    while (count > 0) {
        // 报数n-1轮
        for (int i = 1; i < N; i++) {
            pre = p;    // 初始化
            p = p->next;
        }

        // 移出p结点，首次移出的放在newhead，其他的在newTail中
        if (newHead == nullptr) {
            newHead = new Node{p->data, nullptr};
            newTail = newHead;
        } else {
            newTail->next = new Node{p->data, nullptr};
            newTail = newTail->next;
        }

        // 删除原环p结点
        pre->next = p->next;
        Node* temp = p; // 把p指向地址保存到一个临时指针中防止找不到
        p = p->next;    // p的新指向
        delete temp;    // 删除结点地址

        count--;
    }

    // 将新队列串头
    if (newTail) newTail->next = newHead;
    return newHead;
}

// 打印最终结果
void printList(Node* head, int M) {
    Node* p = head;
    for (int i = 0; i < M; i++) {
        cout << setw(4) << p->data;
        p = p->next;
    }
    cout << endl;
}

// 释放链表内存
void freeList(Node* head,int M) {
    Node* p = head;
    for (int i = 0; i < M; i++) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
}

int main() {
    int M;
    while (cin >> M) {
        int N;
        Node* head = createList(M);

        while (cin.peek() != '\n' && cin >> N) {
            head = josephusRound(head, N, M);
        }

        printList(head, M);
        freeList(head, M);
    }
    return 0;
}