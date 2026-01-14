#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    float old;
    float load;
    Node* left;
    Node* right;
    Node(float load,float old=-1): load(load), left(NULL), right(NULL), old(old) {}
};

class AVL {
public:
    Node* leftRotation(Node* root) {
        Node* newRoot = root->right;
        Node* leftChild = newRoot->left;
        newRoot->left = root;
        root->right = leftChild;
        return newRoot;
    }

    Node* rightRotation(Node* root) {
        Node* newRoot = root->left;
        Node* rightChild = newRoot->right;
        newRoot->right = root;
        root->left = rightChild;
        return newRoot;
    }

    Node* leftRight(Node* root) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    Node* rightLeft(Node* root) {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    int height(Node* root) {
        if (root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    Node* insertCpu(Node* root, float load,float old=-1) {
        if (root == NULL) return new Node(load,old);

        if (load < root->load)
            root->left = insertCpu(root->left, load,old);
        else if (load > root->load)
            root->right = insertCpu(root->right, load,old);
        int bf = height(root->right) - height(root->left);

        if (bf > 1 && load > root->right->load)
            return leftRotation(root);
        if (bf < -1 && load < root->left->load)
            return rightRotation(root);
        if (bf > 1 && load < root->right->load)
            return rightLeft(root);
        if (bf < -1 && load > root->left->load)
            return leftRight(root);

        return root;
    }

    Node* successor(Node* root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, float load) {
        if (root == NULL) return root;
        if (load < root->load)
            root->left = deleteNode(root->left, load);
        else if (load > root->load)
            root->right = deleteNode(root->right, load);
        else {
            if (root->left == NULL || root->right == NULL) {
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            } else {
                Node* temp = successor(root->right);
                root->load = temp->load;
                root->right = deleteNode(root->right, temp->load);
            }
        }

        int bf = height(root->right) - height(root->left);
        if (bf > 1 && height(root->right->right) >= height(root->right->left))
            return leftRotation(root);
        if (bf < -1 && height(root->left->left) >= height(root->left->right))
            return rightRotation(root);
        if (bf > 1 && height(root->right->right) < height(root->right->left))
            return rightLeft(root);
        if (bf < -1 && height(root->left->left) < height(root->left->right))
            return leftRight(root);

        return root;
    }

    Node* leastCpu(Node* root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    Node* AddProcess(Node* root, float process) {
    Node* least = leastCpu(root);
    cout << "Assigning process (load +" << process << ") to CPU with load " << least->load << endl;
    float oldLoad = least->load;  
    float newLoad = oldLoad + process;
    root = deleteNode(root, oldLoad);  
    root = insertCpu(root, newLoad,oldLoad);
    return root;
}


    Node* search(Node* root, float load) {
        if (!root) return NULL;
        if (root->load == load) return root;
        if (load < root->load) return search(root->left, load);
        return search(root->right, load);
    }

    Node* processComplete(Node* root, float load) {
    Node* temp = search(root, load);
    if (!temp) return root;
    cout << "Process completed on CPU (load reset from " << temp->load << " to " << temp->old << ")" << endl;
    float currentLoad = temp->load;
    float oldLoad = temp->old;
    root = deleteNode(root, currentLoad);  
    root = insertCpu(root, oldLoad);
    return root;
}

    void levelOrder(Node* root) {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        queue<Node*> q;
        q.push(root);
        cout << "CPU Loads (Level Order): ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->load << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << "\n";
    }
};

int main() {
    AVL tree;
    Node* root = NULL;

    root = tree.insertCpu(root, 30);
    root = tree.insertCpu(root, 20);
    root = tree.insertCpu(root, 40);
    root = tree.insertCpu(root, 10);
    root = tree.insertCpu(root, 25);

    cout << "Initial CPU Load Distribution:\n";
    tree.levelOrder(root);

    root = tree.AddProcess(root, 13);
    tree.levelOrder(root);
    root = tree.processComplete(root, 23);
    tree.levelOrder(root);

    return 0;
}

