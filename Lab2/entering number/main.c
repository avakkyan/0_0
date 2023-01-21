#include <stdio.h>
int main(){
    int i,n,num,place;
    scanf("%d\n",&n);
    n=n+1;
    int arr[n];
    for (i=0;i<n-1;i++){
        scanf("%d", &arr[i]);
    }
    arr[n-1]=0;
    printf("\n");
    scanf("%d\n",&num);
    scanf("%d",&place);
    for (i=n-1;i>place-2;i--){
        arr[i+1]=arr[i];
    }
    printf("\n");
    arr[place-1]=num;
    for (i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }


    return 0;
}
