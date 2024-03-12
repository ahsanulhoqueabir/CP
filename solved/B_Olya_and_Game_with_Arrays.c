#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort integers in ascending order
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t;
    scanf("%d", &t);  // Read the number of test cases
    
    while (t--) {
        int n;
        scanf("%d", &n);  // Read the number of arrays
        
        long long beauty = 0;  // Initialize the total beauty
        
        for (int i = 0; i < n; i++) {
            int m;
            scanf("%d", &m);  // Read the number of elements in the current array
            
            int a[m];
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[j]);  // Read the elements of the current array
            }
            
            // Sort the array in ascending order
            qsort(a, m, sizeof(int), compare);
            
            // Add the minimum value of the current array to the total beauty
            beauty += a[0];
        }
        
        printf("%lld\n", beauty);
    }
    
    return 0;
}
