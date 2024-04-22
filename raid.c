#include <stdio.h>

void getRaid0(int n, int c, int s, int q, int query[]) {
    int disks = n;
    int stripes_per_disk = s / c;
    for (int i = 0; i < q; i++) {
        int sector_number = query[i];
        int stripe_number = sector_number / (disks * c);
        int disk_number = (sector_number / c) % disks;
        printf("%d %d\n", disk_number, stripe_number);
    }
}

int main(int argc, char *argv[]) {

    char T[3]; 
    int N, C, S, Q;
    scanf("%s %d %d %d %d", T, &N, &C, &S, &Q);

    int query[Q];
    for(int i = 0; i < Q; i++) 
    {
        scanf("%d", &query[i]);
    }

    switch (T[0]) {
        case '0':
            if (T[1] == '1') 
            {
                // getRaid01(N, C, S, Q, query);
            } 
            else 
            {
                getRaid0(N, C, S, Q, query);
            }
            break;
        default:
            break;
    }

    return 0;
}
