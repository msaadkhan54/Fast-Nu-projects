#ifndef KEYWORD_AVL_H
#define KEYWORD_AVL_H

#include <string>
#include <algorithm>
using namespace std;

class AVLNode {
public:
    string key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
};

class KeywordAVL {
private:
    AVLNode* root;

    int h(AVLNode* n) {
        return n ? n->height : 0;
    }

    int balance(AVLNode* n) {
        return n ? h(n->left) - h(n->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(h(y->left), h(y->right)) + 1;
        x->height = max(h(x->left), h(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(h(x->left), h(x->right)) + 1;
        y->height = max(h(y->left), h(y->right)) + 1;

        return y;
    }

    AVLNode* insertNode(AVLNode* node, string key) {
        if (!node) return new AVLNode(key);

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);
        else
            return node;

        node->height = 1 + max(h(node->left), h(node->right));
        int bf = balance(node);

        // LL
        if (bf > 1 && key < node->left->key)
            return rotateRight(node);

        // RR
        if (bf < -1 && key > node->right->key)
            return rotateLeft(node);

        // LR
        if (bf > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL
        if (bf < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    bool searchNode(AVLNode* node, string key) {
        if (!node) return false;
        if (key == node->key) return true;
        if (key < node->key) return searchNode(node->left, key);
        return searchNode(node->right, key);
    }

public:
    KeywordAVL() { root = nullptr; }

    void insert(string key) {
        root = insertNode(root, key);
    }

    bool contains(string key) {
        return searchNode(root, key);
    }
};

#endif
