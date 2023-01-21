#include <iostream>
using namespace std;

int binL(int x, int a[], int size, int start, int end, int mid) {
    while (end > start + 1) {
        if (a[mid] < x) {
            start = mid;
        }
        else {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    if (end < size && a[end] == x) {
        return end + 1;
    }
    else {
        return -1;
    }
}

int binR(int x, int a[], int size, int start, int end, int mid) {
    while (end > start + 1) {
        if (a[mid] <= x) {
            start = mid;
        }
        else {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    if (end <= size && a[end - 1] == x) {
        return end;
    }
    else {
        return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int end = n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int x;
    for (int i = 0; i < m; i++){
        cin >> x;
        cout << binL(x, a, n, -1, end, (-1 + n)/2) << " " << binR(x, a, n, -1, end, (-1 + n)/2) << endl;
    }
    return 0;
}