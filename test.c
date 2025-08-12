#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int x = 5;
    int y = 10;
    int z = 15;
    DataType t = TYPE_INT;

    // create list and ensure all defaults are set
    struct list *l = createLinkedList(t, sizeof(int));
    assert(l->size == 0);
    assert(l->type == t);
    assert(l->dataSize == sizeof(int));
    assert(l->head == NULL);
    assert(l->tail == NULL);
    assert(l != NULL);

    // prepend and append nodes to list
    struct node *node1 = prependNode(l, &x);
    assert(l->size == 1);
    assert(l->head != NULL);
    assert(l->tail != NULL);
    assert(l->head == l->tail);
    int temp = *(int *)(l->head->data);
    assert(temp == x);

    struct node *node2 = prependNode(l, &y);
    assert(l->size == 2);
    assert(l->head != node1);
    assert(l->head == node2);
    assert(l->tail != node2);
    assert(l->tail == node1);
    temp = *(int *)(l->head->data);
    assert(temp == y);
    temp = *(int *)(l->tail->data);
    assert(temp == x);

    struct node *node3 = appendNode(l, &z);
    assert(l->size == 3);
    assert(l->head != node3);
    assert(l->tail == node3);
    assert(l->tail != node2);
    temp = *(int *)(l->tail->data);
    assert(temp == z);

    // test delete
    deleteHead(l);
    assert(l->size == 2);
    assert(l->head == node1);
    deleteHead(l);
    assert(l->size == 1);
    assert(l->head == node3);
    deleteHead(l);
    assert(l->size == 0);
    assert(l->head == NULL);
    assert(l->tail == NULL);
    deleteHead(l);
    assert(l->size == 0);
    assert(l->head == NULL);
    assert(l->tail == NULL);

    node1 = appendNode(l, &x);
    node2 = appendNode(l, &y);
    node3 = appendNode(l, &z);
    assert(l->size == 3);
    assert(l->tail == node3);
    deleteTail(l);
    assert(l->size == 2);
    assert(l->tail == node2);
    deleteTail(l);
    assert(l->size == 1);
    assert(l->tail == node1);
    deleteTail(l);
    assert(l->size == 0);
    assert(l->tail == NULL);

    node1 = appendNode(l, &x);
    node2 = appendNode(l, &y);
    node3 = appendNode(l, &z);
    deleteNode(l, node2);
    assert(l->size == 2);
    assert(l->head == node1);
    assert(l->head->next == node3);
    assert(l->tail == node3);

    // getnode
    struct node *node4 = getNode(l, &z);
    assert(l->size == 2);

    printf("Test print list\n");
    printList(l);

    deleteLinkedList(l);
    printf("All tests passed\n");

    return 0;
}
