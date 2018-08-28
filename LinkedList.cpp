//
// Created by Liming Shao on 2018/8/15.
//

#include "LinkedList.h"
#include <stdio.h>
#include <typeinfo>

void LinkedList::test() {
    LinkedList ins;
    SingleNode *singleList = ins.createLinkedList((SingleNode *)NULL, 1);
    ins.createLinkedList(singleList, 2);
    ins.createLinkedList(singleList, 3);
    ins.createLinkedList(singleList, 4);
    ins.createLinkedList(singleList, 5);
    ins.printLinkedList(singleList);
    SingleNode *newSingleList = ins.inverseLinkedList(singleList);
    ins.printLinkedList(newSingleList);
    int sLen = ins.getLinkedListLength(newSingleList);
    printf("Len = %d\n", sLen);

    ins.destroyLinkedList(&newSingleList);

    DoubleNode *doubleList = ins.createLinkedList((DoubleNode *)NULL, 11);
    ins.createLinkedList(doubleList, 12);
    ins.createLinkedList(doubleList, 13);
    ins.createLinkedList(doubleList, 14);
    ins.createLinkedList(doubleList, 15);
    ins.printLinkedList(doubleList);
    DoubleNode *newDoubleList = ins.inverseLinkedList(doubleList);
    ins.printLinkedList(newDoubleList);
    int dLen = ins.getLinkedListLength(newDoubleList);
    printf("Len = %d\n", dLen);
    ins.destroyLinkedList(&newDoubleList);

}

SingleNode* LinkedList::createLinkedList(SingleNode *head, int val) {
    SingleNode *node = NULL;
    if (head == NULL) {
        node = new SingleNode(val);
        return node;
    }

    node = head;
    while (node->next) {
        node = node->next;
    }

    node->next = new SingleListNode(val);
    return head;
}

DoubleNode* LinkedList::createLinkedList(DoubleNode *head, int val) {
    DoubleNode *node = NULL, *tmp;
    if (head == NULL) {
        node = new DoubleListNode(val);
        return node;
    }

    node = head;
    while (node->next) {
        node = node->next;
    }

    tmp = new DoubleNode(val);
    node->next = tmp;
    tmp->pre = node;

    return head;
}

template <typename T>
void LinkedList::printLinkedList(T *head) {
    if (typeid(T).name() == typeid(SingleNode).name()) {
        printf("Singly Linked Lists: ");
    } else {
        printf("Doubly Linked Lists: ");
    }

    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

SingleNode *LinkedList::inverseLinkedList(SingleNode *head) {
    SingleNode *pre = NULL, *next;

    while (head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

DoubleNode *LinkedList::inverseLinkedList(DoubleNode *head) {
    DoubleNode *pre = NULL, *next;

    while (head) {
        next = head->next;
        head->next = pre;
        head->pre = next;
        pre = head;
        head = next;
    }
    return pre;
}

template <typename T>
void LinkedList::destroyLinkedList(T **list) {
    if (list == nullptr)
        return;
    T *next;
    T *node = *list;
    while (node) {
        next = node->next;
        delete node;
        node = next;
    }

    (*list) = nullptr;
}

template<typename T>
int LinkedList::getLinkedListLength(T *list) {
    int length = 0;
    while (list) {
        list = list->next;
        length++;
    }
    return length;
}


