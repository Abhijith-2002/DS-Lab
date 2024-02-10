#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* head = NULL;
Node* tail = NULL;

void insertNode(int data) {
    if (head == NULL) {
        Node* newNode = createNode(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = createNode(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void readSLL() {
    int data, choice;
    printf("\nReading Linked List...\n");
    do {
        printf("Enter the data : \n");
        scanf("%d", &data);
        insertNode(data);
        printf("Continue adding more elements?(1/0)\n");
        scanf("%d", &choice);
    } while (choice);
    printf("\nOriginal Linked List...\n");
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next != NULL) {
            printf("-->");
        }
        ptr = ptr->next;
    }
}

void removeDuplicate() {
    Node* ptr1 = head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        Node* ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                Node* duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(duplicate);
            }
            else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
    printf("\nRemoved Duplicate Nodes...\n");
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next != NULL) {
            printf("-->");
        }
        ptr = ptr->next;
    }
}

void findMinMax() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* ptr = head;
    int min = ptr->data;
    int max = ptr->data;

    while (ptr != NULL) {
        if (ptr->data < min) {
            min = ptr->data;
        }
        else if (ptr->data > max) {
            max = ptr->data;
        }
        ptr = ptr->next;
    }

    printf("\nMin: %d\n", min);
    printf("\nMax: %d\n", max);
}

void findSum() {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    Node* ptr = head;
    int sum = 0;
    while (ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    printf("\nSum: %d\n", sum);
}

void makeCopy() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* headCopy = NULL;
    Node* tailCopy = NULL;
    Node* ptr = head;

    while (ptr != NULL) {
        Node* newNode = createNode(ptr->data);
        if (headCopy == NULL) {
            headCopy = newNode;
            tailCopy = newNode;
        }
        else {
            tailCopy->next = newNode;
            tailCopy = newNode;
        }
        ptr = ptr->next;
    }

    ptr = headCopy;
    printf("\nList Successfully Copied...\n");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        if (ptr->next != NULL) {
            printf("-->");
        }
        ptr = ptr->next;
    }
}

int main() {
    readSLL();
    removeDuplicate();
    findMinMax();
    findSum();
    makeCopy();
    return 0;
}
