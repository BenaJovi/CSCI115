/*  Author: Jovani Benavides
*  Course: CSCI-115
*  Assignment 4: BST Traversal 
* 
*/

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
      void printPreOrder(Node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            printPreOrder(root->LeftChild);
            printPreOrder(root->RightChild);
            
        }
    }
       void printInOrder(Node *root) {
        if (root != NULL) {
            printInOrder(root->LeftChild);
            cout << root->data << " ";
            printInOrder(root->RightChild);
        }
    }
};

int main() {
    BST inorderTree;
    BST preorderTree;
// Part A: Construct a Binary Tree from Preorder and Inorder Traversal
cout<<"Preorder:"<<endl;
    // Insert elements into the BST
    int elements[] = {20,8,4,12,23,24}; // numbers from the sample
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) { // loop to insert all numbers into the BST
        inorderTree.insert(elements[i]);
        cout << elements[i] << " ";
    }
    cout << endl;
cout<<"Inorder:"<<endl;
   int elements2[] = {4,8,12,20,23,24}; // numbers from the sample
    for (int i = 0; i < sizeof(elements2) / sizeof(elements2[0]); i++) { // loop to insert all numbers into the BST
        preorderTree.insert(elements2[i]);
        cout << elements2[i] << " ";
    }
    cout << endl;
// Part B: Use the constructed BST to perform a postorder walk
    // Print the tree in Post-order 
    cout << "Post-order: ";
    preorderTree.printPostOrder(preorderTree.getRoot());
    cout << endl;

      // Print the tree in Post-order 
    cout << "Post-order: ";
    inorderTree.printPostOrder(inorderTree.getRoot());
    cout << endl;
    return 0;
}
