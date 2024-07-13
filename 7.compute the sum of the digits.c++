#include <iostream>

// Function to compute the sum of digits of a number
int sumOfDigits(int n) {
    int sum = 0; // Initialize sum to 0

    // Iterate through each digit of the number
    while (n > 0) {
        sum += n % 10; // Add the last digit of n to sum
        n /= 10;       // Remove the last digit from n
    }

    return sum; // Return the computed sum of digits
}

// Test example
int main() {
    int num;

    // Input number for which sum of digits is to be calculated
    std::cout << "Enter a number: ";
    std::cin >> num;

    // Calculate sum of digits
    int result = sumOfDigits(num);

    // Output the sum of digits
    std::cout << "Sum of digits of " << num << " is: " << result << std::endl;

    return 0; // Exit the program
}
