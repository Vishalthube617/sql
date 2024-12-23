#include <stdio.h>
#include <stdbool.h>

#define P 5  // Processes
#define R 3  // Resources

int main() {
    // Maximum resources needed by each process
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Resources allocated to each process
    int alloc[P][R] = {
        {0, 1, 0},
        {2, 1, 1},
        {3, 2, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Available resources
    int avail[R] = {3, 3, 2};

    // Need matrix: Max - Allocated
    int need[P][R];
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Work vector and Finish array
    int work[R];
    bool finish[P] = {0};  // All processes initially unfinished
    for (int i = 0; i < R; i++) work[i] = avail[i];

    // Safe sequence array
    int safeSeq[P], idx = 0;
    
    // Banker's algorithm to find safe sequence
    for (int count = 0; count < P; count++) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < R; j++)
                    if (need[i][j] > work[j]) {
                        canFinish = false;
                        break;
                    }
                if (canFinish) {
                    // Update work and mark process as finished
                    for (int j = 0; j < R; j++)
                        work[j] += alloc[i][j];
                    finish[i] = true;
                    safeSeq[idx++] = i;
                    found = true;
                    break;
                }
            }
        }
        if (!found) { printf("System is in an unsafe state.\n"); return 0; }
    }

    // If all processes finished, print the safe sequence
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < P; i++) printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}

/*
Explanation:
Input Matrices:

max[P][R]: Maximum resources needed by each process.
alloc[P][R]: Resources allocated to each process.
avail[R]: Available resources in the system.
Need Matrix Calculation:

need[i][j] = max[i][j] - alloc[i][j] computes the remaining resources each process needs.
Work Vector:

work[]: Holds the available resources, initialized with the system's available resources (avail[]).
Safe Sequence Calculation:

Finish Array: Tracks which processes have been completed.
In each iteration, we check if a process can finish (i.e., its Need is less than or equal to the Work vector). If so, we simulate the process finishing and update the Work vector (by adding the allocated resources of that process back to the available pool).
The process is marked as finished and added to the safeSeq[] array.
Termination:

If no process can finish in any iteration, the system is in an unsafe state.
If all processes can finish, the system is in a safe state, and the safe sequence is printed */
/*For the input:
Maximum Matrix
0   1   0
2   1   1
3   2   2
2   1   1
0   0   2
Allocated Matrix:
0   1   0
2   1   1
3   2   2
2   1   1
Available Resources:
3   3   2
System is in a safe state.
Safe sequence: P1 P3 P4 P0 P2*/