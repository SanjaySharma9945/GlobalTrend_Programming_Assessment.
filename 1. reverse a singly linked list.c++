#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a singly linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *next = nullptr; // Initialize pointers prev and next to nullptr
    while (head) { // Loop until head is nullptr
        next = head->next; // Store the next node in the original list
        head->next = prev; // Reverse the current node's next pointer to point to prev
        prev = head; // Move prev pointer to current node
        head = next; // Move head pointer to next node in the original list
    }
    return prev; // Return the new head of the reversed list
}

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head; // Initialize a temporary pointer to iterate through the list
    while (temp != nullptr) { // Loop until temp is nullptr
        std::cout << temp->val << " "; // Print the value of the current node
        temp = temp->next; // Move temp pointer to the next node
    }
    std::cout << std::endl; // Print a newline after printing all nodes
}

// Function to create a linked list from user input
ListNode* createLinkedList() {
    ListNode* dummy = new ListNode(0); // Create a dummy node to simplify list construction
    ListNode* current = dummy; // Initialize current pointer to the dummy node
    
    int n; // Variable to store number of nodes
    std::cout << "Enter number of nodes: "; // Prompt user to enter number of nodes
    std::cin >> n; // Read number of nodes from input
    
    std::cout << "Enter values for each node:" << std::endl; // Prompt user to enter values for each node
    for (int i = 0; i < n; ++i) { // Loop to read values for each node
        int value; // Variable to store node value
        std::cin >> value; // Read node value from input
        current->next = new ListNode(value); // Create a new node with the read value and link it to current node
        current = current->next; // Move current pointer to the newly created node
    }
    
    return dummy->next; // Return the head of the created linked list (excluding the dummy node)
}

// Test example
int main() {
    ListNode* head = createLinkedList(); // Create a linked list from user input
    
    std::cout << "Original list: ";
    printList(head); // Print the original list
    
    ListNode* reversedHead = reverseList(head); // Reverse the list and get the new head of reversed list
    
    std::cout << "Reversed list: ";
    printList(reversedHead); // Print the reversed list
    
    return 0; // Exit the program
}
