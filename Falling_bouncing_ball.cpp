#include <iostream>
#include <cmath>
using namespace std;

void simulateBouncingBall(double h0, double k, int maxBounces, double g = 9.81) {
    double height = h0;
    double time = 0;
    double totalTime = 0;

    for (int n = 1; n <= maxBounces; ++n) {
        double impactSpeed = sqrt(2 * g * height);
        double bounceTime = sqrt(2 * height / g);

        cout << "Bounce " << n << ": " << endl;
        cout << "    Height: " << height << " m" << endl;
        cout << "    Impact Speed: " << impactSpeed << " m/s" << endl;
        cout << "    Time to impact: " << bounceTime << " s" << endl;

        totalTime += 2 * bounceTime;
        height *= k * k;  // Energy loss with coefficient of restitution

        if (height < 1e-4) { // Stop if height is negligible
            cout << "Ball has stopped bouncing.\n";
            break;
        }
    }
    cout << "Total simulation time: " << totalTime << " s" << endl;
}

int main() {
    double h0, k;
    int maxBounces;

    cout << "Enter initial height (m): ";
    cin >> h0;
    cout << "Enter coefficient of restitution (k): ";
    cin >> k;
    cout << "Enter maximum number of bounces: ";
    cin >> maxBounces;

    simulateBouncingBall(h0, k, maxBounces);
    return 0;
}
