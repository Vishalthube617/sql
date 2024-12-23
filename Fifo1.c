#include <stdio.h>  

int main()  
{  
    int incomingStream[] = {4, 1, 2, 4, 5};  
    int pageFaults = 0;  
    int frames = 3;  
    int m, n, s, pages;   
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);   
    printf("Incoming \tFrame 1 \tFrame 2 \tFrame 3\n");  
    int temp[frames];  
    
    // Initialize frames as empty (using -1 to denote empty frame)
    for (m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    
    // Process each page in the incoming stream
    for (m = 0; m < pages; m++)  
    {  
        s = 0;   
        
        // Check if the page is already in one of the frames
        for (n = 0; n < frames; n++)  
        {  
            if (incomingStream[m] == temp[n])  
            {  
                s++;  
                pageFaults--; // Page is already in a frame, no need to increment fault  
            }  
        }  
        
        pageFaults++; // Assume page fault unless found in frames
        
        // If there is no match, replace the page in one of the frames
        if (s == 0)  
        {  
            // Replace the page in the frame (using cyclic replacement strategy)
            temp[(pageFaults - 1) % frames] = incomingStream[m];  
        }
        
        // Print current state of frames
        printf("%d\t\t", incomingStream[m]);  
        for (n = 0; n < frames; n++)  
        {  
            if (temp[n] != -1)  
                printf("%d\t\t", temp[n]);  
            else  
                printf("-\t\t");  
        }  
        printf("\n");  
    }  
    
    // Print total number of page faults
    printf("\nTotal Page Faults: %d\n", pageFaults);  
    return 0;  
}  
