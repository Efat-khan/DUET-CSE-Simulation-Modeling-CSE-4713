#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, p;
    int T;
    int count = 0; // To count the number of equilibrium points
    
    // Taking input for the number of iterations
    cout << "Enter number of iterations: ";
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        // Generating random values for a, b, c, d
        a = rand() % 1000;        // Random number between 0 and 999 for a
        b = rand() % 1000;        // Random number between 0 and 999 for b
        c = rand() % 100;         // Random number between 0 and 99 for c
        d = rand() % 1000;        // Random number between 0 and 999 for d

        // Print values of a, b, c, d
        cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << endl;

        // Calculate price p
        p = (a - c) / (b + d);

        // Print the calculated price
        cout << "Price: " << p << endl;

        // Check for equilibrium point using a tolerance to avoid floating-point precision issues
        double left_side = a - b * p;
        double right_side = c + d * p;
        
        // Using a small tolerance for floating point comparison
        const double tolerance = 1e-6;

        if (fabs(left_side - right_side) < tolerance) {
            cout << "Equilibrium Point found!" << endl;
            cout << "Price: " << p << endl;
            count++;  // Increment count when equilibrium is found
        }
        cout << endl;
    }

    // Print total equilibrium points found
    cout << "Total Equilibrium Points: " << count << endl;

    return 0;
}
