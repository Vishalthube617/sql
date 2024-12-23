#include <stdio.h>

int main() {
    // Hardcoded reference string and number of frames
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = 8;         // Number of pages
    int frames = 3;    // Number of memory frames
    int memory[3] = {-1, -1, -1}; // Initialize memory to -1 (empty)
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

        // If page is not in memory, replace a page
        if (!found) {
            int replaceIndex = -1, farthest = -1;

            // If an empty frame is available, use it
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find the page to replace
            if (replaceIndex == -1) {
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (memory[j] == pages[k]) {
                            break;
                        }
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
            }

            // Replace the page in memory
            memory[replaceIndex] = pages[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}

