#include <iostream>

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1; // Initialize result to 1, as factorial of 0 and 1 is 1

    // Calculate factorial iteratively
    for (int i = 2; i <= n; ++i) {
        result *= i; // Multiply result by current value of i
    }

    return result; // Return the calculated factorial
}

// Test example
int main() {
    int n;

    // Input number for which factorial is to be calculated
    std::cout << "Enter a number: ";
    std::cin >> n;

    // Calculate factorial of n
    int result = factorial(n);

    // Output the factorial
    std::cout << "Factorial of " << n << " is: " << result << std::endl;

    return 0; // Exit the program
}
