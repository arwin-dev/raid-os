#include <stdio.h>

void getRaid0(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[]) {
    for(int i = 0; i < queryCount; i++)
    {       
        int offset = query[i] % chunkSize;
        int chunkNumber = query[i] / chunkSize;
        int stripe = chunkNumber % hardDiskCount;
        int disk = (chunkNumber / hardDiskCount) * chunkSize + offset;
        printf("%d %d\n", stripe, disk);
    } 
}

int main(int argc, char *argv[]) {
    char raidMode[3]; 
    int hardDiskCount, chunkSize;
    int sectorCount, queryCount;
    scanf("%s %d %d %d %d", raidMode, &hardDiskCount, &chunkSize, &sectorCount, &queryCount);

    int query[queryCount];
    for(int i = 0; i < queryCount; i++) 
    {
        scanf("%d", &query[i]);
    }

    switch (raidMode[0]) {
        case '0':
            if (raidMode[1] == '1') 
            {
                // getRaid01(N, C, S, Q, query);
            } 
            else 
            {
                getRaid0(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            }
            break;
        default:
            break;
    }

    return 0;
}
