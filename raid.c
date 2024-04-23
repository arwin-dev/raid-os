#include <stdio.h>

void getRaid0(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[]) 
{
    for(int i = 0; i < queryCount; i++)
    {       
        int offset = query[i] % chunkSize;
        int chunkNumber = query[i] / chunkSize;
        int stripe = chunkNumber % hardDiskCount;
        int disk = (chunkNumber / hardDiskCount) * chunkSize + offset;
        printf("%d %d\n", stripe, disk);
    } 
}

void getRaid01(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[])
{
    for(int i = 0; i < queryCount; i++)
    {       
        int stripe = query[i] / (hardDiskCount / 2);
        int disk1 = query[i] % (hardDiskCount / 2);
        int disk2 = disk1 + (hardDiskCount / 2);
        printf("%d %d %d \n", disk1, stripe, disk2);
    }
}

void getRaid1(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[])
{
    for(int i = 0; i < queryCount; i++)
    {
        printf("0 %d 1\n", query[i]);
    }
}

void getRaid10(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[])
{
    for(int i = 0; i < queryCount; i++)
    {       
        int stripe = query[i] / (hardDiskCount / 2);
        int disk1 = (query[i] % (hardDiskCount / 2)) * 2;
        int disk2 = disk1 + 1;
        printf("%d %d %d \n", disk1, stripe, disk2);
    }
}

void getRaid4(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[])
{
    for(int i = 0; i < queryCount; i++)
    {       
        int stripe = query[i] / (hardDiskCount - 1);
        int disk1 = query[i] % (hardDiskCount - 1);
        int disk2 = hardDiskCount - 1;
        printf("%d %d %d \n", disk1, stripe, disk2);
    }
}

void getRaid5(int hardDiskCount, int chunkSize, int sectorCount, int queryCount, int query[])
{
    for(int i = 0; i < queryCount; i++)
    {       
        int stripe = query[i] / (hardDiskCount - 1);
        int disk1 = query[i] % hardDiskCount;
        int disk2 = hardDiskCount - 1 - (stripe % hardDiskCount);
        printf("%d %d %d \n", disk1, stripe, disk2);
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

    switch (raidMode[0]) 
    {
        case '0':
            if (raidMode[1] == '1') 
            {
                getRaid01(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            }
            else 
            {
                getRaid0(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            }
            break;
        case '1':
            if(raidMode[1] == '0')
            {
                getRaid10(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            }
            else
            {
                getRaid1(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            }
            break;
        case '4':
                getRaid4(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            break;
        case '5':
                getRaid5(hardDiskCount, chunkSize, sectorCount, queryCount, query);
            break;
        default:
            break;
    }

    return 0;
}
