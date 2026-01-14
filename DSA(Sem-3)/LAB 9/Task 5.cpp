#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int bidID;
    float amount;
    Node* left;
    Node* right;
    int height;

    Node(int id, float amt)
        : bidID(id), amount(amt), left(NULL), right(NULL), height(1) {}
};

class AVL {
public:
    int getHeight(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        if (!n) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    Node* insert(Node* root, int id, float amount) {
        if (!root)
            return new Node(id, amount);

        if (amount < root->amount)
            root->left = insert(root->left, id, amount);
        else if (amount > root->amount)
            root->right = insert(root->right, id, amount);
        else
            return root; 

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalance(root);

        if (bf > 1 && amount < root->left->amount)
            return rightRotate(root);
        if (bf < -1 && amount > root->right->amount)
            return leftRotate(root);
        if (bf > 1 && amount > root->left->amount) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (bf < -1 && amount < root->right->amount) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Node* deleteNodeByAmount(Node* root, float amount) {
        if (!root) return NULL;

        if (amount < root->amount)
            root->left = deleteNodeByAmount(root->left, amount);
        else if (amount > root->amount)
            root->right = deleteNodeByAmount(root->right, amount);
        else {
            
            if (!root->left || !root->right) {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->bidID = temp->bidID;
                root->amount = temp->amount;
                root->right = deleteNodeByAmount(root->right, temp->amount);
            }
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalance(root);
        if (bf > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (bf > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (bf < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (bf < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* searchByID(Node* root, int id) {
        if (!root) return NULL;
        if (root->bidID == id) return root;
        Node* left = searchByID(root->left, id);
        if (left) return left;
        return searchByID(root->right, id);
    }

    Node* deleteByID(Node* root, int bidID) {
        Node* target = searchByID(root, bidID);
        if (!target) {
            cout << "Bid ID " << bidID << " not found!\n";
            return root;
        }
        cout << "Deleting bid ID " << bidID << " (amount " << target->amount << ")\n";
        return deleteNodeByAmount(root, target->amount);
    }

    Node* findHighest(Node* root) {
        if (!root) return NULL;
        while (root->right) root = root->right;
        return root;
    }

    Node* findSecondHighest(Node* root) {
        if (!root || (!root->left && !root->right))
            return NULL;

        Node* parent = NULL;
        Node* current = root;

        while (current->right) {
            parent = current;
            current = current->right;
        }

        if (current->left) {
            Node* temp = current->left;
            while (temp->right) temp = temp->right;
            return temp;
        }

        return parent;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << "(" << root->bidID << ", " << root->amount << ") ";
        inorder(root->right);
    }
};

int main() {
    AVL tree;
    Node* root = NULL;

    root = tree.insert(root, 101, 500.0);
    root = tree.insert(root, 102, 700.0);
    root = tree.insert(root, 103, 300.0);
    root = tree.insert(root, 104, 900.0);
    root = tree.insert(root, 105, 800.0);

    cout << "All bids (inorder by amount): ";
    tree.inorder(root);
    cout << "\n\n";

    Node* highest = tree.findHighest(root);
    Node* second = tree.findSecondHighest(root);

    cout << "Highest Bid: ID=" << highest->bidID << ", Amount=" << highest->amount << endl;
    cout << "Second Highest Bid: ID=" << second->bidID << ", Amount=" << second->amount << endl;

    cout << "\n--- Deleting Bid ID 104 ---\n";
    root = tree.deleteByID(root, 104);

    cout << "All bids after deletion: ";
    tree.inorder(root);
    cout << "\n\n";

    highest = tree.findHighest(root);
    second = tree.findSecondHighest(root);

    cout << "After Deletion:\n";
    cout << "Highest Bid: ID=" << highest->bidID << ", Amount=" << highest->amount << endl;
    cout << "Second Highest Bid: ID=" << second->bidID << ", Amount=" << second->amount << endl;

    return 0;
}

