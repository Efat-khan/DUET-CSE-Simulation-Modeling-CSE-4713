#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, flag = 0; // Number of data and break flag
    cout << "Enter the number of work times you want to input: ";
    cin >> n;

    vector<int> work_time(n); // Vector to store work times
    cout << "Enter the values of work time (in minutes): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> work_time[i];
    }

    // Print the table header
    cout << "Documentation_no\tS_time\tW_time\tF_time\tC_time\tBreak" << endl;

    int start_time = 0; // Start time for each task
    int cumulative_time = 0; // Tracks the cumulative work time for breaks

    // Loop through each task
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t"; // Documentation number

        // Start time
        cout << start_time << "\t";

        // Work time
        cout << work_time[i] << "\t";

        // Finish time
        start_time += work_time[i];
        cout << start_time << "\t";

        // Update cumulative work time
        cumulative_time += work_time[i];
        cout << cumulative_time << "\t";

        // Check if a break is required
        if (cumulative_time >= 60) { // If cumulative work time reaches or exceeds 60 minutes
            cumulative_time = 0; // Reset cumulative time
            start_time += 5;     // Add 5 minutes for a break
            flag = 1;            // Set break flag
        }

        // Print if a break occurred
        if (flag) {
            cout << "Yes";
        } else {
            cout << "No";
        }

        // Reset break flag for next iteration
        flag = 0;

        cout << endl; // New line for the next row
    }

    return 0;
}
