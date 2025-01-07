#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Demand and Supply functions
    double demand_intercept = 12.4, demand_slope = 1.2;
    double supply_intercept = 8.0, supply_slope = 0.6;

    cout<<"Equilibriam quantity and price: "<<endl;
    double equ_price = (demand_intercept-supply_intercept)/(demand_slope+supply_slope);
    double equ_quantity = demand_intercept - demand_slope*equ_price;
    cout<<"Price* :"<<equ_price<<endl;
    cout<<"Quantity* :"<<equ_quantity<<endl;
    // Initial price
    double P_prev = 1.0; // P0
    int iterations = 10; // Number of iterations

    cout << fixed << setprecision(2);
    cout << "Iteration\tPrice (P)\tQuantity (Q)\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < iterations; i++) {
        // Calculate quantity supplied based on previous price
        double Q_supply = supply_intercept + supply_slope * P_prev;

        // Calculate price for the current demand = supply
        double P_current = (demand_intercept - Q_supply) / demand_slope;

        // Display results
        cout << i + 1 << "\t\t" << P_current << "\t\t" << Q_supply << endl;

        // Update previous price for next iteration
        P_prev = P_current;
    }

    return 0;
}
