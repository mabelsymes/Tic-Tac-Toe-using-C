#include <stdio.h>

// Function to clear the input buffer.
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}