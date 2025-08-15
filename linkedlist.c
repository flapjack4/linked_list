#include <stdlib.h>
#include "linkedlist.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

struct list *createLinkedList(DataType type, size_t dataSize) {
    struct list *list = (struct list *)malloc(sizeof(struct list));
    if (!list) {
        perror("Error: allocating list");
        exit(1);
    }

    list->size = 0;
    list->type = type;
    list->dataSize = dataSize;
    list->head = list->tail = NULL;
    return list;
}

void deleteNode(struct list *l, struct node *node) {
    if (node == l->head)
        deleteHead(l);
    else if (node == l->tail)
        deleteTail(l);

    struct node *preNode = l->head;
    while (preNode->next != node)
        preNode = preNode->next;

    struct node *delNode = preNode->next;
    preNode->next = preNode->next->next;
    free(delNode->data);
    free(delNode);
    l->size--;
}

void deleteLinkedList(struct list *l) {
    struct node *curNode = l->head;
    while (curNode != NULL) {
        struct node *temp = curNode->next;
        free(curNode->data);
        free(curNode);
        curNode = temp;
    }
    free(l);
}

struct node *createNode(void *data, size_t dataSize) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (!node) {
        perror("Error: allocating node");
        exit(1);
    }

    node->data = malloc(dataSize);
    memcpy(node->data, data, dataSize);
    node->next = NULL;
    return node;
}

struct node *prependNode(struct list *l, void *data) {
    struct node *newNode = createNode(data, l->dataSize);
    if (!l->head) {
        l->head = l->tail = newNode;
    } else {
        newNode->next = l->head;
        l->head = newNode;
    }
    l->size++;

    return l->head;
}

struct node *appendNode(struct list *l, void *data) {
    struct node *newNode = createNode(data, l->dataSize);
    if (!l->head) {
        l->head = l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->size++;

    return l->tail;
}

int deleteHead(struct list *l) {
    struct node *prevHead = l->head;
    if (l->size < 1) 
        return 1;
    else if (l->size == 1)
        l->head = l->tail = NULL;
    else 
        l->head = l->head->next;

    free(prevHead->data);
    free(prevHead);
    l->size--;
    return 0;
}

int deleteTail(struct list *l) {
    struct node *oldTail = l->tail;
    if (l->size < 1)
        return 1;
    else if (l->size == 1)
        l->head = l->tail = NULL;
    else {
        struct node *preTail= l->head;
        while (preTail->next != l->tail)
            preTail = preTail->next;

        l->tail = preTail;
        l->tail->next = NULL;
    }
    
    free(oldTail->data);
    free(oldTail);
    l->size--;
    return 0;
}

int compareNodeData(struct node *node, DataType type, void *val) {
    switch (type) {
        case TYPE_INT:
            if (*(int *)node->data == *(int *)val)
                return 0;
            break;
        case TYPE_DOUBLE:
            if (*(double *)node->data == *(double *)val)
                return 0;
            break;
        case TYPE_STRING:
            break;
        default:
            printf("Unknown type\n");
    }
    return -1;
}

/*
 * get the first node in the list with the value val.
*/
struct node *getNode(struct list *l, void *val) {
    struct node *curNode = l->head;
    while (curNode != NULL) {
        if (compareNodeData(curNode, l->type, val) == 0)
            return curNode;
        curNode = curNode->next;
    }
    return NULL;
}

void printNode(struct node *node, DataType type) {
    switch (type) {
        case TYPE_INT:
            printf("%d\n", *(int *)node->data);
            break;
        case TYPE_DOUBLE:
            printf("%f\n", *(double *)node->data);
            break;
        case TYPE_STRING:
            printf("%s\n", (char *)node->data);
            break;
        default:
            printf("Unknown type\n");
    }
}

void printList(struct list *l) {
    struct node *curNode = l->head;
    if (curNode == NULL) {
        perror("List is empty");
        return;
    }

    while (curNode != NULL) {
        printNode(curNode, l->type);
        curNode = curNode->next;
    }
}










