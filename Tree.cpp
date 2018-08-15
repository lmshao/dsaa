//
// Created by Liming Shao on 2018/7/18.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

#include "Tree.h"

// 层序遍历，-1表示为NULL
Node *Tree::createBiTree(const int *arr, int size, int index) {
    if (index >= size || arr[index] == -1){
        return nullptr;
    }

    Node *node = new Node;

    if (index != size) {
        node->value = arr[index];
        node->left = createBiTree(arr, size, 2*(index+1)-1);
        node->right = createBiTree(arr, size, 2*(index+1));
    } else {
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void Tree::destoryBiTree(Node *tree) {
    if (tree == NULL)
        return;

    destoryBiTree(tree->left);
    if (tree->left)
        tree->left = NULL;

    destoryBiTree(tree->right);
    if (tree->right)
        tree->right = NULL;

    delete tree;
}

void Tree::preOrderRecur(Node *tree) {
    if (!tree) return;

    std::cout << tree->value << " ";
    preOrderRecur(tree->left);
    preOrderRecur(tree->right);
}

void Tree::inOrderRecur(Node *tree) {
    if (!tree) return;

    inOrderRecur(tree->left);
    std::cout << tree->value << " ";
    inOrderRecur(tree->right);
}

void Tree::posOrderRecur(Node *tree) {
    if (!tree) return;

    posOrderRecur(tree->left);
    posOrderRecur(tree->right);
    std::cout << tree->value << " ";
}

#include <stack>

void Tree::preOrderUnRecur(Node *tree) {
    if (!tree) return;

    std::stack<Node*> nodeStack;
    nodeStack.push(tree);
    Node *root = nullptr;
    while (!nodeStack.empty()) {
        root = nodeStack.top();
        nodeStack.pop();
        std::cout << root->value << " ";

        if (root->right)
            nodeStack.push(root->right);

        if (root->left)
            nodeStack.push(root->left);
    }
}

void Tree::inOrderUnRecur(Node *tree) {
    if (!tree) return;

    std::stack<Node*> nodeStack;
    Node *root = tree;

    while (!nodeStack.empty() || root) {
       if (root) {
           nodeStack.push(root);
           root = root->left;
       } else {
           root = nodeStack.top();
           std::cout << root->value << " ";

           nodeStack.pop();
           root = root->right;
       }
    }
}

void Tree::posOrderUnRecur(Node *tree) {
    if (!tree) return;

    std::stack<Node*> nodeStack;
    nodeStack.push(tree);

    Node *last = nullptr;
    Node *current = nullptr;

    while (!nodeStack.empty()) {
        current = nodeStack.top();

        if ((current->left) && (last != current->left)
            && ((last != current->right) || !current->right)) {
            nodeStack.push(current->left);
        } else if(current->right && (last != current->right)) {
            nodeStack.push(current->right);
        } else {
            std::cout << current->value << " ";
            last = current;
            nodeStack.pop();
        }
    }
}

void testTree() {
    int array[15] = {1,2,3,4,5,6,7,8,-1,-1,-1,-1,-1,9,10};
    Tree *ins = new Tree;
    Node *tree = ins->createBiTree(array, 15, 0);

    std::cout << "\n前序遍历（递归）：" << std::endl;
    ins->preOrderRecur(tree);

    std::cout << "\n前序遍历（非递归）：" << std::endl;
    ins->preOrderUnRecur(tree);

    std::cout << "\n中序遍历（递归）：" << std::endl;
    ins->inOrderRecur(tree);

    std::cout << "\n中序遍历（非递归）：" << std::endl;
    ins->inOrderUnRecur(tree);

    std::cout << "\n后序遍历（递归）：" << std::endl;
    ins->posOrderRecur(tree);

    std::cout << "\n后序遍历（非递归）：" << std::endl;
    ins->posOrderUnRecur(tree);

    ins->destoryBiTree(tree);
    tree = NULL;
}

