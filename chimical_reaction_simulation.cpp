#include <bits/stdc++.h>
using namespace std;

int main() {
    // Constants for reaction rates
    float k1 = 0.008, k2 = 0.002; // Reaction rate constants
    float a = 100, b = 50, c = 0; // Initial concentrations of A, B, and C
    float dt = 0.1; // Time step
    float T = 0;    // Total elapsed time

    // Variables for updated concentrations
    float a_nw, b_nw, c_nw;

    // Print header for the output table
    cout << "Time\t" << "A\t" << "B\t" << "C" << endl;

    // Simulate the reaction using Euler's method
    for (int i = 0; i <= 100; i++) { // Iterate for 100 steps (T = 10 with dt = 0.1)
        // Print current time and concentrations
        cout << fixed << setprecision(2) << T << "\t" << a << "\t" << b << "\t" << c << endl;

        // Calculate new concentrations based on reaction equations
        a_nw = a + ((k2 * c) - (k1 * a * b)) * dt;
        b_nw = b + ((k2 * c) - (k1 * a * b)) * dt;
        c_nw = c + ((k1 * a * b * 2) - (k2 * c)) * dt;

        // Update concentrations for the next iteration
        a = a_nw;
        b = b_nw;
        c = c_nw;

        // Increment time
        T += dt;
    }

    return 0;
}
