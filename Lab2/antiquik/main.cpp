#include <iostream>
using namespace std;
int main() {
    int i, n, mid;
    cin >> n;
    int mass[n];
    for (i=0; i<n; i++) {
        mass[i] = i + 1;
    }
    for (int i=2; i<n; i++){
        swap(mass[i],mass[i/2]);
    }

    for (i=0; i<n; i++){
        cout << mass[i] << " ";
    }
    return 0;
}
