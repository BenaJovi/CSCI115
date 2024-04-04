#include <iostream>
using namespace std;

class Node {
public:
    Node(int data){
        this->data = data;
        this->LeftChild = NULL;
        this->RightChild = NULL;
    };
    int data;
    Node* LeftChild;
    Node* RightChild;
};

class BST {
private:
    Node* root;

    Node* insertNode(Node *node, int data) {
        if (node == NULL) {
            return new Node(data);
        }

        if (data < node->data) {
            node->LeftChild = insertNode(node->LeftChild, data);
        } else if (data > node->data) {
            node->RightChild = insertNode(node->RightChild, data);
        }
        return node;
    }

public:
    BST() : root(nullptr) {}
    Node* getRoot(){ return this->root; };

    void insert(int data) {
        root = insertNode(root, data);
    }

    void printPostOrder(Node *root) {
        if (root != NULL) {
            printPostOrder(root->LeftChild);
            printPostOrder(root->RightChild);
            cout << root->data << " ";
        }
    }

    int findLargest(Node *root) {
        Node* current = root;
        while (current->RightChild != NULL) {
            current = current->RightChild;
        }
        return current->data;
    }

    bool search(Node *root, int key) {
        if (root == NULL) {
            return false;
        }

        if (key == root->data) {
            return true;
        } else if (key < root->data) {
            return search(root->LeftChild, key);
        } else {
            return search(root->RightChild, key);
        }
    }
};

int main() {
    BST bst;

    // Insert elements into the BST
    int elements[] = {7, 20, 8, 9, 6, 1, 19, 15, 2, 10};
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        bst.insert(elements[i]);
        cout << elements[i] << " ";
    }
    cout << endl;

    // Print the tree in post-order traversal
    cout << "Post-order: ";
    bst.printPostOrder(bst.getRoot());
    cout << endl;

    // Find the largest key in the tree
    cout << "Largest element in the list is: " << bst.findLargest(bst.getRoot()) << endl;

    // Search for keys
    int key;
    cout << "Insert a number for look up >> ";
    cin >> key;
    if (bst.search(bst.getRoot(), key)) {
        cout << key << endl;
    } else {
        cout << key << " is not a member of the list / " << key << " not found" << endl;
    }

    return 0;
}
