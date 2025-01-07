#include <iostream>
#include <cmath>
using namespace std;

// Function to count the number of digits in a given number
int count_digit(int number) {
    int count = 0;
    // Handle the case when the number is 0, which has 1 digit
    if (number == 0) {
        return 1;
    }
    // Count digits by repeatedly dividing the number by 10
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

// Mid-square method for generating random numbers
int mid_square(int seed, int digit) {
    // Square the seed to get a larger number
    int square = seed * seed;
    
    // Find the number of digits in the square
    int numDigit = count_digit(square);

    // Calculate where to start extracting the middle digits
    int start = (numDigit / 2) - (digit / 2);

    // Extract the middle 'digit' number of digits from the square
    int divisor = pow(10, start); // Determine the divisor to shift digits
    square = square / divisor;    // Remove digits before the middle

    // Get the last 'digit' number of digits after the shift
    seed = square % static_cast<int>(pow(10, digit));

    return seed;
}

int main() {
    int seed, digit, random_number;

    // Input seed, digit count, and the number of random numbers to generate
    cout << "Enter Seed: ";
    cin >> seed;

    cout << "Enter Digit: ";
    cin >> digit;

    cout << "Number of random numbers: ";
    cin >> random_number;

    cout << "Random numbers: " << endl;

    // Generate and display the random numbers using the mid-square method
    for (int i = 0; i < random_number; i++) {
        seed = mid_square(seed, digit);  // Update seed using the mid-square method
        cout << i + 1 << ". " << seed << endl;
    }

    return 0;
}
