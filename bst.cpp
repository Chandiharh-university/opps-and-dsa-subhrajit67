#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
    Node* root;
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }
    void inorder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    bool search(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    int findHeight(Node* node) const {
        if (node == nullptr) {
            return -1;
        }
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(Node* node) const {
        if (node == nullptr) {
            return true;
        }
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }
    int countNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value) {
        root = insert(root, value);
    }
    void inorder() const {
        inorder(root);
        cout << endl;
    }
    bool search(int value) const {
        return search(root, value);
    }
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }
    int height() const {
        return findHeight(root);
    }
    bool isBalanced() const {
        return isBalanced(root);
    }
    int countNodes() const {
        return countNodes(root);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal: ";
    bst.inorder();

    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << endl;

    bst.deleteValue(50);
    cout << "Inorder traversal after deleting 50: ";
    bst.inorder();

    cout << "Height of the tree: " << bst.height() << endl;
    cout << "Is the tree balanced? " << (bst.isBalanced() ? "Yes" : "No") << endl;
    cout << "Total number of nodes: " << bst.countNodes() << endl;

    return 0;
}
