#include <iostream>
#include <algorithm> // For std::max

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to recursively calculate the maximum path sum
int maxPathSumHelper(TreeNode* root, int& maxSum) {
      if (!root) return 0; // Base case: if root is nullptr, return 0

      int leftSum = std::max(0, maxPathSumHelper(root->left, maxSum)); // Recursively calculate max path sum from left subtree
      int rightSum = std::max(0, maxPathSumHelper(root->right, maxSum)); // Recursively calculate max path sum from right subtree
      
      int currentSum = root->val + leftSum + rightSum; // Calculate the current path sum through the root
      maxSum = std::max(maxSum, currentSum); // Update maxSum with the maximum of currentSum and maxSum
      
      return root->val + std::max(leftSum, rightSum); // Return the maximum path sum possible from root to either left or right subtree
}

// Function to find the maximum path sum in a binary tree
int maxPathSum(TreeNode* root) {
      int maxSum = INT_MIN; // Initialize maxSum to the minimum integer value
      maxPathSumHelper(root, maxSum); // Call helper function to recursively calculate max path sum
      return maxSum; // Return the final maximum path sum
}

// Function to create a binary tree from user input (for testing purposes)
TreeNode* createTree() {
      int value;
      std::cout << "Enter node value (-1 for null): ";
      std::cin >> value;

      if (value == -1) {
         return nullptr;
      }

      TreeNode* root = new TreeNode(value);
      std::cout << "Enter left child of " << value << ":" << std::endl;
      root->left = createTree();
      std::cout << "Enter right child of " << value << ":" << std::endl;
      root->right = createTree();

      return root;
}

// Test example
int main() {
      TreeNode* root = createTree(); // Create a binary tree from user input
      int result = maxPathSum(root); // Find the maximum path sum in the tree
      std::cout << "Maximum path sum in the binary tree: " << result << std::endl; // Output the result
      return 0; // Exit the program
}
