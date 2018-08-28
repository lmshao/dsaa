//
// Created by Liming Shao on 2018/7/18.
//

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

#include "Tree.h"

void Tree::testTree() {
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

    std::cout << "\n层序遍历（递归）：" << std::endl;
    ins->levelOrderRevur(tree);

    int depth = ins->getDepth(tree);
    std::cout << "\nDepth = " << depth << std::endl;

    ins->destoryBiTree(tree);
    tree = NULL;
}

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

void printNodeAtLevel(Node *tree, int level) {
    if (!tree || level < 1)
        return;

    if (level == 1) {
        std::cout << tree->value << " ";
        return;
    }

    printNodeAtLevel(tree->left, level-1);
    printNodeAtLevel(tree->right, level-1);
}

void Tree::levelOrderRevur(Node *tree) {
    if (!tree)
        return;

    int depth = getDepth(tree);
    for (int i = 0; i <= depth ; ++i) {
        printNodeAtLevel(tree, i);
        std::cout << std::endl;
    }
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

int Tree::getDepth(Node *tree) {
    if (tree == nullptr)
        return 0;

    int lh, rh, maxh;
    lh = getDepth(tree->left);
    rh = getDepth(tree->right);

    maxh = lh > rh ? lh : rh;
    return maxh+1;
}


void Tree::insertBST(Node *tree, int key) {
    if (tree == nullptr)
        return;
    bool res;
    Node *node = nullptr, *newNode;

    res = searchBST(tree, key, &node);
    if (res)
        return;

    newNode = new Node;
    newNode->value = key;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (node->value > key)
        node->left = newNode;

    else
        node->right = newNode;

    return;
}

// return true查找到了false未查找到
// node 查找到的节点或者最后一个节点
bool Tree::searchBST(Node *tree, int key, Node **node) {
    Node *node1 = nullptr;
    bool res = false;

    if (tree == nullptr)
        return false;

    while (tree) {
        node1 = tree;
        if (tree->value == key) {
            res = true;
            break;
        }

        if (tree->value > key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }

    if (node != nullptr)
        *node = node1;

    return res;
}



