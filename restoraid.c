#include <stdio.h>
#include <stdlib.h>

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

// Function to replace non-alphanumeric characters with underscore
char replace_non_alphanumeric(char c) {
    return is_alphanumeric(c) ? c : '_';
}

int main() {
    char T[3]; // RAID level
    int N, C, S, W; // Number of disks, size of chunks, sectors per disk, and working disks
    scanf("%s %d %d %d %d", T, &N, &C, &S, &W);

    int i, j, k;
    if (W > 0) {
        int* working_disks = (int*)malloc(W * sizeof(int));
        for (i = 0; i < W; i++) {
            scanf("%d", &working_disks[i]);
        }

        char** data = (char**)malloc(S * sizeof(char*));
        for (i = 0; i < S; i++) {
            data[i] = (char*)malloc(W * sizeof(char));
            for (j = 0; j < W; j++) {
                scanf("%hhd", &data[i][j]);
            }
        }

        // Dump content
        for (i = 0; i < S; i++) {
            for (j = 0; j < C; j++) {
                char ch = data[i][0]; // Initialize with first disk's value
                for (k = 1; k < W; k++) {
                    if (T[0] == '0' || T[0] == '1') {
                        ch ^= data[i][k];
                    } else if (T[0] == '4' || T[0] == '5') {
                        ch ^= data[i][k];
                    }
                }
                printf("%c", replace_non_alphanumeric(ch));
            }
        }
        printf("\n");

        // Free allocated memory
        for (i = 0; i < S; i++) {
            free(data[i]);
        }
        free(data);
        free(working_disks);
    } else {
        printf("DATA LOST\n");
    }

    return 0;
}
