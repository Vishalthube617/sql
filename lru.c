#include <stdio.h>

int main() {
    // Hardcoded reference string and number of frames
    int p[] = {7, 0, 1, 2, 0, 3, 0, 4}; // Page references
    int n = 8;  // Number of pages
    int f = 3;  // Number of frames
    int mem[3] = {-1, -1, -1}; // Memory frames initialized to -1 (empty)
    int last[3] = {0, 0, 0};   // Last used times for frames
    int faults = 0; // Page fault counter

    for (int i = 0; i < n; i++) {
        int hit = 0;

        // Check if the page is already in memory
        for (int j = 0; j < f; j++) {
            if (mem[j] == p[i]) {
                hit = 1;        // Page hit
                last[j] = i;    // Update last used time
                break;
            }
        }

        // If page is not in memory, replace the least recently used page
        if (!hit) {
            int lru = 0;

            // Find the least recently used frame
            for (int j = 1; j < f; j++) {
                if (last[j] < last[lru]) {
                    lru = j;
                }
            }

            // Replace the page in the LRU frame
            mem[lru] = p[i];
            last[lru] = i; // Update last used time
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}

