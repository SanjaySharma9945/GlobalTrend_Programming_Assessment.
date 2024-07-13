#include <iostream>
#include <unordered_map>
#include <algorithm>

// Function to find the length of the longest substring without repeating characters
int lengthOfLongestSubstring(const std::string& s) {
    int n = s.length(); // Get the length of the input string
    std::unordered_map<char, int> charMap; // Hash map to store characters and their indices
    int maxLength = 0; // Variable to store the maximum length of substring without repeating characters
    int left = 0; // Left pointer of the sliding window

    for (int right = 0; right < n; ++right) { // Iterate through the string with the right pointer
        if (charMap.find(s[right]) != charMap.end()) { // If current character is already in the map
            left = std::max(charMap[s[right]] + 1, left); // Move left pointer to avoid repeating characters
        }
        charMap[s[right]] = right; // Update the index of current character in the map
        maxLength = std::max(maxLength, right - left + 1); // Update maxLength with the current window size
    }

    return maxLength; // Return the maximum length of substring without repeating characters
}

// Test example
int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input; // User inputs a string
    
    int result = lengthOfLongestSubstring(input); // Calculate the length of longest substring without repeating characters
    
    std::cout << "Length of the longest substring without repeating characters: "
              << result << std::endl; // Output the result
    
    return 0; // Exit the program
}
