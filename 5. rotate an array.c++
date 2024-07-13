#include <iostream>
#include <vector>
#include <algorithm> // Include for std::reverse

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Adjust k in case it's larger than the array size

    // Reverse the entire array
    std::reverse(nums.begin(), nums.end());
    
    // Reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);
    
    // Reverse the rest of the elements
    std::reverse(nums.begin() + k, nums.end());
}

// Test example
int main() {
    std::vector<int> nums;
    int n, k;
    
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
    
    // Input number of steps to rotate
    std::cout << "Enter number of steps to rotate: ";
    std::cin >> k;
    
    rotate(nums, k); // Rotate the array in-place
    
    // Output the rotated array
    std::cout << "Rotated array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0; // Exit the program
}
