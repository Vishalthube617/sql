#include <stdio.h>

#define P 5  // Processes
#define R 3  // Resources

int main() {
    // Example: Maximum matrix (Max demand for each process)
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Example: Allocated matrix (Allocated resources to each process)
    int alloc[P][R] = {
        {0, 1, 0},
        {2, 1, 1},
        {3, 2, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Need matrix to store the result
    int need[P][R];

    // Calculate Need matrix and print it
    printf("Need Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
