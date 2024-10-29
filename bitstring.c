#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {
    int i, j, k = 0;
    int u[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[] = {1, 3, 4, 5, 8}; 
    int b[] = {1, 2, 3, 6, 8, 10}; 
    int sa[N] = {0}, sb[N] = {0}, us[N] = {0}, es[N] = {0}, fs[N] = {0}, c[N] = {0}, d[N] = {0};

    
    printf("Bitstring of super set:\n");
    for (i = 0; i < N; i++) {
        us[i] = 1; 
        printf("%d\t", us[i]);
    }

    
    printf("\nBitstring of A:\n");
    for (i = 0; i < N; i++) {
        sa[i] = 0; 
        for (j = 0; j < sizeof(a)/sizeof(a[0]); j++) {
            if (a[j] == u[i]) {
                sa[i] = 1;
                break;
            }
        }
        printf("%d\t", sa[i]);
    }

   
    printf("\nBitstring of B:\n");
    for (i = 0; i < N; i++) {
        sb[i] = 0; 
        for (j = 0; j < sizeof(b)/sizeof(b[0]); j++) {
            if (b[j] == u[i]) {
                sb[i] = 1;
                break;
            }
        }
        printf("%d\t", sb[i]);
    }

    
    printf("\n----------------------------------\nUnion bit set:\n");
    for (i = 0; i < N; i++) {
        es[i] = (sa[i] == 1 || sb[i] == 1) ? 1 : 0;
        printf("%d\t", es[i]);
    }

    printf("\nUnion number set:\n");
    k = 0; 
    for (i = 0; i < N; i++) {
        if (es[i] == 1) {
            c[k++] = u[i];
            printf("%d\t", c[k-1]);
        }
    }

   
    printf("\n----------------------------------\nIntersection bit set:\n");
    for (i = 0; i < N; i++) {
        fs[i] = (sa[i] == 1 && sb[i] == 1) ? 1 : 0;
        printf("%d\t", fs[i]);
    }

    printf("\nIntersection number set:\n");
    k = 0; 
    for (i = 0; i < N; i++) {
        if (fs[i] == 1) {
            d[k++] = u[i];
            printf("%d\t", d[k-1]);
        }
    }

    printf("\n");
    return 0;
}

