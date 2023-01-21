#include <iostream>
using namespace std;

int main() {
    int num_of_el, i;
    cin >> num_of_el;
    int pyramid[num_of_el];
    for (i = 0; i < num_of_el; i++) {
        cin >> pyramid[i];
    }
    int flag1 = 0;
    int flag2 = 0;
    for (i = 0; i < num_of_el/2 - 1; i++) {
        if (pyramid[i] > pyramid[2 * i + 1]){
            flag1 = 1;
            break;
        }

        if (pyramid[i] > pyramid[2 * i + 2]) {
            flag2 = 1;
            break;
        }
    }
    if (flag1 == 1 || flag2 == 1 ) {
        cout << "NO";
    } else cout << "YES";


    return 0;
}
