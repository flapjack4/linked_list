#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h>

typedef enum {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STRING
} DataType;

struct list {
    int size; // number of nodes in the list
    DataType type; // the type of the data in the list
    size_t dataSize;
    struct node *head;
    struct node *tail;
};

struct node {
    void *data;
    struct node *next;
};

struct list *createLinkedList(DataType type, size_t dataSize);
void deleteNode(struct list *l, struct node *);
void deleteLinkedList(struct list *);
struct node *createNode(void *, size_t);
struct node *prependNode(struct list *, void *);
struct node *appendNode(struct list *, void *);
int deleteHead();
int deleteTail();
int compareNodeData(struct node *, DataType, void *);
struct node *getNode(struct list *, void *);
void printNode(struct node *, DataType);
void printList(struct list *);

#endif
