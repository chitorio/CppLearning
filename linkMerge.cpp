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
    Node* result = nullptr;
    Node* p = A;
    Node* q = B;

    while (p) {
        while (q) {
            if (p->data <= q->data) {
                result = p;
                p = p->next;
            } else {
                result = q;
                q = q->next;
            }
            result = result->next;
        }
    }

    while (q) append(result, q->data);

    return result;
}

int main() {
    string line;
    Node* A;
    Node* B;

    getline(cin, line);
    stringstream ss1(line);
    int data;
    while (ss1 >> data) {
        append(A, data);
    }

    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> data) {
        append(B, data);
    }

    Node* result = linkMerge(A, B);

    for (Node* p = result; p; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " ";
    }
    cout << endl;

    return 0;
}