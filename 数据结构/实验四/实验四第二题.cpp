#include <bits/stdc++.h>
using namespace std;

// 链表节点的结构体
typedef struct Node {
    int data;
    Node* next;
}Node, *LinkList;

// 在链表尾部添加新节点
void append(LinkList* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// 判断链表是否包含环
int hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // 没有环
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1; // 存在环
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 0; // 没有环
}

// 打印链表的元素
void printList(Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    cout<<endl; 
}

int main() {
    Node* head = NULL;

    // 在链表中添加一些元素
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    // 创建一个包含环的链表
    Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = head; // 将链表的最后一个节点连接到头部，形成环

    // 判断链表是否包含环
    if (hasCycle(head)) {
        printf("链表包含环\n");
    } else {
        printf("链表不包含环\n");
    }

    return 0;
}

