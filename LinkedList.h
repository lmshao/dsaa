//
// Created by Liming Shao on 2018/8/15.
//

#ifndef DSAA_LINKEDLIST_H
#define DSAA_LINKEDLIST_H

typedef struct SingleListNode {
    int val;
    struct SingleListNode* next;
    explicit SingleListNode(int val) : val(val), next(nullptr){}
}SingleNode;

typedef struct DoubleListNode {
    int val;
    struct DoubleListNode* pre;
    struct DoubleListNode* next;
    explicit DoubleListNode(int val) : val(val), pre(nullptr), next(nullptr){}
}DoubleNode;


class LinkedList {
public:
    static void test();

    SingleNode *createLinkedList(SingleNode *head, int val);
    DoubleNode *createLinkedList(DoubleNode *head, int val);

    template <typename T>
    void destroyLinkedList(T **list);

    template <typename T>
    void printLinkedList(T *head);

    SingleNode *inverseLinkedList(SingleNode *head);
    DoubleNode *inverseLinkedList(DoubleNode *head);

    template <typename T>
    int getLinkedListLength(T *list);

};




#endif //DSAA_LINKEDLIST_H
