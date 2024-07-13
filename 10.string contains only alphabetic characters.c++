#include <iostream>
#include <cctype> // For std::isalpha

// Function to check if a string contains only alphabetic characters
bool containsOnlyAlphabetic(const std::string& str) {
    // Iterate through each character in the string
    for (char c : str) {
        // Check if the character is not alphabetic
        if (!std::isalpha(c)) {
            return false; // Return false if non-alphabetic character found
        }
    }
    return true; // Return true if all characters are alphabetic
}

// Test example
int main() {
    std::string input;

    // Input string to check
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Check if the string contains only alphabetic characters
    bool result = containsOnlyAlphabetic(input);

    // Output the result
    std::cout << std::boolalpha; // Print bool values as true/false
    std::cout << "The string contains only alphabetic characters: " << result << std::endl;

    return 0; // Exit the program
}
