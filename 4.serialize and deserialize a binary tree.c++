#include <iostream>
#include <sstream> // For std::ostringstream and std::istringstream
#include <string>  // For std::string

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Serialize the binary tree to a string
std::string serialize(TreeNode* root) {
    if (!root) {
        return "null,"; // If node is null, represent it as "null"
    }
    
    // Convert the current node to string and serialize left and right subtrees recursively
    return std::to_string(root->val) + ","
         + serialize(root->left)
         + serialize(root->right);
}

// Deserialize the string to reconstruct the binary tree
TreeNode* deserialize(std::istringstream& ss) {
    std::string token;
    std::getline(ss, token, ','); // Read next token separated by ','

    if (token == "null") {
        return nullptr; // If token is "null", return nullptr indicating null node
    }

    // Convert token to integer (node value) and create a new TreeNode
    TreeNode* root = new TreeNode(std::stoi(token));
    root->left = deserialize(ss); // Deserialize left subtree recursively
    root->right = deserialize(ss); // Deserialize right subtree recursively
    
    return root; // Return the constructed TreeNode
}

// Test example
int main() {
    // Example tree creation for testing purposes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    std::string serializedTree = serialize(root);
    std::cout << "Serialized tree: " << serializedTree << std::endl;

    // Deserialize the string to reconstruct the binary tree
    std::istringstream iss(serializedTree);
    TreeNode* reconstructedTree = deserialize(iss);

    // Clean up memory (optional, depending on application)
    // In a real application, you would handle memory management more carefully
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0; // Exit the program
}
