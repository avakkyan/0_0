#include <iostream>
using namespace std;
int partition (int arr[], int low, int high){
    int i=low-1;
    int pivot = arr[low];
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
    }
}
int partition_r (int arr[], int low, int high){
    srand(time(nullptr));
    int random = low+rand()%(high-low);
    std::swap(arr[random], arr[low]);
    return partition (arr,low,high);

}
void qsort(int arr[], int low, int high ){
    if (low<high){
        int pi = partition_r(arr,low,high);

        qsort(arr,low,pi);
        qsort(arr,pi+1,high);
    }
}
int main() {
    int n,m;
    cin >> n;
    int arr1[n];
    for (int i=0; i<n; i++){
        cin >> arr1[i];
    }
    cin >> m;
    int arr2 [m];
    for (int i=0; i<m; i++){
        cin >> arr2[i];
    }

    qsort(arr1,0,n-1);
    qsort(arr2,0,m-1);


    int k1=1;
    for (int  i=1; i<n; i++) {
        if (arr1[i] != arr1[i-1]){
            k1++;
        }
    }
    int k2=1;
    for (int  i=1; i<m; i++) {
        if (arr2[i] != arr2[i - 1]) {
            k2++;
        }
    }
    int arr3[n+m];
    for (int i=0; i<n; i++){
        arr3[i] = arr1[i];
    }
    for (int i=0; i<m; i++){
        arr3[i+n] = arr2[i];
    }
    qsort(arr3,0,n+m-1);
    for (int  i=0; i<n+m; i++) {
    }

    int k3=1;
    for (int  i=1; i< n+m; i++) {
        if (arr3[i] != arr3[i - 1]) {
            k3++;
        }
    }

    if (min(k1,k2)==k3 ){
        cout << "YES";
    }
    else{ cout << "NO"; }
return 0;
}
