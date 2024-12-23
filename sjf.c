#include <stdio.h>

int main() {
    int n;

    // Taking input for number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], at[n], wt[n], tat[n], completed[n];
    int total_wt = 0, total_tat = 0, current_time = 0;

    // Accept Process IDs using a for loop
    printf("Enter Process IDs: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter Process ID for Process %d: ", i + 1);
        scanf("%d", &pid[i]);
    }

    // Accept Burst Times using a separate for loop
    printf("Enter Burst Times: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Accept Arrival Times using a separate for loop
    printf("Enter Arrival Times: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        completed[i] = 0;  // Initially, no process is completed
    }

    // Calculate waiting time and turnaround time for each process
    for (int count = 0; count < n; count++) {
        int idx = -1;
        int min_bt = 9999;

        // Find the process with the smallest burst time that has arrived and not yet completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= current_time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        // If no process can be executed (i.e., all are waiting), move the current time forward
        if (idx == -1) {
            current_time++;
            count--;
            continue;
        }

        // Calculate the waiting time and turnaround time for the selected process
        wt[idx] = current_time - at[idx];
        tat[idx] = wt[idx] + bt[idx];

        // Update total waiting time and total turnaround time
        total_wt += wt[idx];
        total_tat += tat[idx];

        // Update the current time
        current_time += bt[idx];

        // Mark the process as completed
        completed[idx] = 1;
    }

    // Output the results
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], at[i], wt[i], tat[i]);
    }

    // Calculating and printing average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;

}













