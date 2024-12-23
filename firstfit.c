#include <stdio.h>

#define MAX_BLOCKS 10

int main() {
    int block_sizes[MAX_BLOCKS], process_allocations[MAX_BLOCKS];
    int num_blocks, num_processes, process_sizes[MAX_BLOCKS];

    // Input memory block sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < num_blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
        process_allocations[i] = -1; // Initially, no process is allocated
    }

    // Input process sizes
    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_sizes[i]);
    }

    // First-fit memory allocation
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_blocks; j++) {
            if (block_sizes[j] >= process_sizes[i]) {
                process_allocations[j] = i;  // Allocate process i to block j
                block_sizes[j] -= process_sizes[i]; // Reduce block size
                break;
            }
        }
    }

    // Output allocation results
    printf("\nMemory Allocation:\n");
    for (int i = 0; i < num_blocks; i++) {
        if (process_allocations[i] != -1)
            printf("Block %d -> Process %d\n", i + 1, process_allocations[i] + 1);
        else
            printf("Block %d -> Free\n", i + 1);
    }

    return 0;
}

