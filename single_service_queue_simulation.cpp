#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of N (number of tasks): ";
    cin >> n;

    // Arrays to store different timings and metrics
    vector<int> AT(n + 1), ST(n + 1), CAT(n + 1), QL(n + 1), IDT(n + 1), CDT(n + 1);
    int NAT, NDT, DIF;

    // Input Arrival Time
    cout << "Enter Arrival Times (space-separated): " << endl;
    int cumulative_arrival = 0; // Tracks cumulative arrival time
    for (int i = 1; i <= n; i++) {
        cin >> AT[i];
        cumulative_arrival += AT[i];
        CAT[i] = cumulative_arrival; // Cumulative Arrival Time
    }

    // Input Start Time
    cout << "Enter Start Times (space-separated): " << endl;
    for (int i = 1; i <= n; i++) {
        cin >> ST[i];
        QL[i] = 0;    // Initialize Queue Length to 0
        IDT[i] = 0;   // Initialize Idle Time to 0
    }

    // Initialize variables
    NAT = CAT[2];      // Next Arrival Time
    NDT = ST[1];       // Next Departure Time
    CDT[1] = ST[1];    // Completion Time for the first task
    int clock = 0;     // Tracks the current time
    int I = 2;         // Task index for Arrival Time
    int J = 1;         // Task index for Departure Time

    // Simulation starts
    while (true) {
        // If all tasks are processed, exit the loop
        if (I > n) {
            goto finish;
        }

        // Calculate difference between next arrival and next departure
        DIF = NAT - NDT;

        if (DIF < 0) {
            // If arrival happens before departure
            clock = NAT;
            NAT = CAT[I + 1]; // Update the next arrival time
            QL[I] = I - J;    // Update Queue Length
            I++;
        } else if (DIF > 0) {
            // If departure happens before arrival
            if ((I - J) > 1) {
                finish:
                clock = NDT;
                CDT[J + 1] = CDT[J] + ST[J + 1]; // Update Completion Time
                NDT = CDT[J + 1];                // Update Next Departure Time
                J++;
            } else {
                IDT[I] = DIF; // Update Idle Time
                goto process_task;
            }
        } else {
            // If arrival and departure times are equal
            QL[I] = QL[I - 1];

            process_task:
            clock = NAT;
            NAT = CAT[I + 1]; // Update next arrival time
            CDT[J + 1] = CAT[I] + ST[J + 1]; // Update completion time
            NDT = CDT[J + 1];                // Update next departure time
            J++;
            I++;
        }

        // Exit loop if all departures are processed
        if (J >= n) {
            break;
        }
    }

    // Output the results
    cout << "Output:" << endl;

    // Cumulative Arrival Time
    cout << "CAT : ";
    for (int i = 1; i <= n; i++) {
        cout << CAT[i] << " ";
    }
    cout << endl;

    // Completion Time
    cout << "CDT : ";
    for (int i = 1; i <= n; i++) {
        cout << CDT[i] << " ";
    }
    cout << endl;

    // Idle Time
    cout << "IDT : ";
    for (int i = 1; i <= n; i++) {
        cout << IDT[i] << " ";
    }
    cout << endl;

    // Queue Length
    cout << "QL : ";
    for (int i = 1; i <= n; i++) {
        cout << QL[i] << " ";
    }
    cout << endl;

    return 0;
}
