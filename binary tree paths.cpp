#include <iostream>
#include <vector>
#include <string>
#include <sstream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
std::string join(const std::vector<std::string>& parts, const std::string& delimiter) {
    std::ostringstream oss;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) {
            oss << delimiter;
        }
        oss << parts[i];
    }
    return oss.str();
}
void findPaths(TreeNode* node, std::vector<std::string>& paths, std::vector<std::string>& currentPath) {
    if (!node) return;

    currentPath.push_back(std::to_string(node->val));

    if (!node->left && !node->right) {
        paths.push_back(join(currentPath, "->"));
    } else {
        findPaths(node->left, paths, currentPath);
        findPaths(node->right, paths, currentPath);
    }

    currentPath.pop_back();
}
std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> paths;
    std::vector<std::string> currentPath;
    findPaths(root, paths, currentPath);
    return paths;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    std::vector<std::string> result = binaryTreePaths(root);

    std::cout << "Root-to-leaf paths:" << std::endl;
    for (const std::string& path : result) {
        std::cout << path << std::endl;
    }
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
