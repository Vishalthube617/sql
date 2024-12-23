#include <stdio.h>

int main() {
    // Hardcoded reference string and number of frames
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = 8;         // Number of pages
    int frames = 3;    // Number of memory frames
    int memory[3] = {-1, -1, -1}; // Initialize memory to -1 (empty)
    int front = 0;     // Points to the oldest page
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1; // Page hit
                break;
            }
        }

        // If page is not in memory, replace the oldest page
        if (!found) {
            memory[front] = pages[i];
            front = (front + 1) % frames; // Move to the next oldest frame
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}

