#include <stdio.h>

int main() {
    int i,j,n,key;
    scanf("%d\n",&n);
    int arr[n];
    for (i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
        for (j = 1; j < n; j++) {
            key = arr[j];
            i = j - 1;
            while ( i>=0 & arr[i] > key) {
                arr[i + 1] = arr[i];
                i = i - 1;
            }
            arr[i + 1] = key;
        }
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return 0;
    }