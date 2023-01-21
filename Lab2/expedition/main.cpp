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
    int i, j, m,n,num_of_tr, k;
    cin >> n >> m;
    int raft[n*m];
    for ( i=0; i<n*m; i++){
        cin >>raft[i];
    }
    cin >> num_of_tr;
    int travelers[num_of_tr];
    for ( i=0; i<num_of_tr; i++){
        cin >>travelers[i];
    }

    qsort(raft,0,n*m-1);
    qsort(travelers,0,num_of_tr-1);
//    for ( i=0; i<n*m; i++) {
//      cout << " " <<raft[i];}
//    cout  << "\n";
//    for ( i=0; i<num_of_tr; i++){
//        cout <<  " " <<travelers[i];
//    }


    k=0;
    int plot=n*m;
    int l=(plot)-1;
    int r=num_of_tr-1;
    while ((r+1)*(l+1)>0) {
        if (travelers[r]<=raft[l]){
            k++;
            r--;
            l--;
        }
        else {
            r--;
        }
    }
    cout << k;

    return 0;
}