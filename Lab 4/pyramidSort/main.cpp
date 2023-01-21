#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    while(2*i + 1< n){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if (left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if (arr[i] >= arr[largest]){
            break;
        }
        else{
            swap (arr[i], arr[largest]);
            i = largest;
        }
    }
}

void buildHeap(int arr[], int n){
    for (int i = (n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--){
        swap (arr[0], arr[i]);
        n=n-1;
        heapify(arr, n, 0);
    }
}

int main() {
    int num_of_el, i;
    cin >> num_of_el;
    int pyramid[num_of_el];
    for (i = 0; i < num_of_el; i++) {
        cin >> pyramid[i];
    }
    heapSort(pyramid, num_of_el);

    for (i = 0; i < num_of_el; i++) {
        cout << pyramid[i] << ' ';
    }

    return 0;
}
