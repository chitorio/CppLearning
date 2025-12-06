#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// 建立链表
void append(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* p = head;
        while (p->next) p = p->next;
        p->next = newNode;
    }
}

// 合并链表
Node* linkMerge(Node* A, Node* B) {
    Node* noresult = new Node{-1, nullptr};
    Node* tail = noresult;
    
    Node* p = A;
    Node* q = B;

    while (p && q) {
        int value;
        if (p->data < q->data) {
            value = p->data;
            p = p->next;
        } else if (q->data < p->data) {
            value = q->data;
            q = q->next;
        } else {
            value = p->data;
            p = p->next;
            q = q->next;
        }

        if (tail == noresult || tail->data != value) {
            tail->next = new Node{value, nullptr};
            tail = tail->next;
        }
    }

    while (p) {
        if (tail->data != p->data) {
            tail->next = new Node{p->data, nullptr};
            tail = tail->next;
        }
        p = p->next;
    }
    while (q) {
        if (tail->data != q->data) {
            tail->next = new Node{q->data, nullptr};
            tail = tail->next;
        }
        q = q->next;
    }

    return noresult->next;
}

int main() {
    string line;
    Node* A = nullptr;
    Node* B = nullptr;

    getline(cin, line);
    stringstream ss1(line);
    int data;
    while (ss1 >> data) append(A, data);

    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> data) append(B, data);

    Node* result = linkMerge(A, B);

    for (Node* p = result; p; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " ";
    }
    cout << endl;

    return 0;
}