//
// Created by Liming Shao on 2018/7/18.
//

#ifndef DSAA_TREE_H
#define DSAA_TREE_H

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
}Node;

class Tree {
public:

    void destoryBiTree(Node *tree);

// 递归方式前序遍历
    void preOrderRecur(Node* tree);
// 递归方式中序遍历
    void inOrderRecur(Node* tree);
// 递归方式后序遍历
    void posOrderRecur(Node* tree);

// 非递归方式
    void preOrderUnRecur(Node* tree);
    void inOrderUnRecur(Node* tree);
    void posOrderUnRecur(Node* tree);

    Node* createBiTree(const int arr[], int size, int index);

};



void testTree();


#endif //DSAA_TREE_H
