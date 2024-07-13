#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element and std::max_element

// Function to find the maximum difference between any two elements in an array
int maxDifference(std::vector<int>& nums) {
    // Check if the array has at least two elements
    if (nums.size() < 2) {
        return 0; // If less than two elements, return 0 (no valid difference)
    }

    // Find the minimum and maximum elements in the array
    int minElement = *std::min_element(nums.begin(), nums.end());
    int maxElement = *std::max_element(nums.begin(), nums.end());

    // Calculate and return the maximum difference
    return maxElement - minElement;
}

// Test example
int main() {
    std::vector<int> nums;
    int n;

    // Input size of array
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // Input array elements
    std::cout << "Enter elements of array: ";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    // Calculate maximum difference
    int result = maxDifference(nums);

    // Output the maximum difference
    std::cout << "Maximum difference between any two elements in the array is: " << result << std::endl;

    return 0; // Exit the program
}
