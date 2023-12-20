#include <bits/stdc++.h>
using namespace std;

// ����ڵ�Ľṹ��
typedef struct Node {
    int data;
    Node* next;
}Node, *LinkList;

// ������β������½ڵ�
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

// �ж������Ƿ������
int hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // û�л�
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1; // ���ڻ�
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 0; // û�л�
}

// ��ӡ�����Ԫ��
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

    // �����������һЩԪ��
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    // ����һ��������������
    Node* lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = head; // ����������һ���ڵ����ӵ�ͷ�����γɻ�

    // �ж������Ƿ������
    if (hasCycle(head)) {
        printf("���������\n");
    } else {
        printf("����������\n");
    }

    return 0;
}

