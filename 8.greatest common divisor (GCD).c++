#include <iostream>

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    // Euclidean algorithm to find GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Return the GCD
}

// Test example
int main() {
    int num1, num2;

    // Input two numbers for which GCD is to be calculated
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Calculate GCD of num1 and num2
    int result = gcd(num1, num2);

    // Output the GCD
    std::cout << "GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;

    return 0; // Exit the program
}
