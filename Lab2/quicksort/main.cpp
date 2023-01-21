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
int main()
{
     int i,n;
     cin >> n;
     int arr[n];
     for (i=0; i<n;i++){
         cin>>arr[i];
     }

     qsort(arr,0,n-1);
    for (i=0; i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}