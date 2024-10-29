#include <stdio.h>

int main() 
{
    int a[10], b[10], c[20], k = 0, m, j, i, n, temp;

    printf("\nEnter the size of the first array (max 10): ");
    scanf("%d", &n);
    if (n > 10) {
        printf("Size exceeds maximum limit of 10.\n");
        return 1;
    }
    
    printf("\nEnter the first array elements:\n");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    printf("\nThe first array elements are:");
    for (i = 0; i < n; i++) 
    {
        printf(" %d", a[i]);
    }
    
    printf("\nEnter the size of the second array (max 10): ");
    scanf("%d", &m);
    if (m > 10) 
    {
        printf("Size exceeds maximum limit of 10.\n");
        return 1;
    }
    
    printf("\nEnter the elements of the second array:\n");
    for (j = 0; j < m; j++) 
    {
        scanf("%d", &b[j]);
    }
    
    printf("\nThe second array elements are:");
    for (j = 0; j < m; j++) 
    {
        printf(" %d", b[j]);
    }

    // Sort the first array
    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (a[i] > a[j])
             {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Sort the second array
    for (i = 0; i < m; i++) 
    {
        for (j = i + 1; j < m; j++)
         {
            if (b[i] > b[j]) 
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("\nThe first array after sort:");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
    
    printf("\nThe second array after sort:");
    for (j = 0; j < m; j++) {
        printf(" %d", b[j]);
    }

    // Merge the two sorted arrays
    printf("\nThe array after merge and sort:");
    i = k = 0;
    j = 0;

    while (i < n && j < m)
     {
        if (a[i] <= b[j]) 
        {
            c[k++] = a[i++];
        } 
        else 
        {
            c[k++] = b[j++];
        }
    }

    while (i < n) 
    {
        c[k++] = a[i++];
    }

    while (j < m) 
    {
        c[k++] = b[j++];  // Changed i to j here
    }

    for (k = 0; k < n + m; k++)
     {
        printf(" %d", c[k]);
    }
    
    printf("\n");
    return 0;
}

