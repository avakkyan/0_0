#include <iostream>
#include <string>
#include <vector>
using namespace std;


int parent (int i){
    return (i-1)/2;
}
void shiftUp(pair <int,int> a[], int i)
{
    while (i > 0 && a[parent(i)].first > a[i].first) {
        swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}
void siftDown(pair <int,int> a[],int n){
    int i=0;
    while(2*i + 1< n){
        int left = 2*i+1;
        int right = 2*i+2;
        int least = left;
        if (right < n && a[right].first < a[left].first){
            least = right;
        }
        if (a[i].first <= a[least].first){
            break;
        }
        else{
            swap (a[i], a[least]);
            i = least;
        }
    }
}
void push(pair <int,int> a[], int size, int value, int i)
{
    a[size].first=value;
    a[size].second=i;
}


int extract_min(pair <int,int> a[], int size)
{
    int result;
    if (size == 0){
        return -1;
    }
    else {
        result = a[0].first;
    }
    return result;
}

int main() {
    pair<int,int> a[100000];
    string str;
    int element, key, size=0, i=0;
    while (cin >> str) {
        ++i;
        if (str == "push") {
            cin >> element;
            push(a, size, element, i);
            size++;
            shiftUp(a,size-1);
        }
        if (str == "extract-min") {
            if (size == 0) {
                cout << '*' << "\n";
            }
            else {
                cout << extract_min(a, size) << "\n";
                size--;
                swap(a[0], a[size]);
                siftDown(a,size);
            }
        }
        if (str == "decrease-key") {
            cin >> key >> element;
            int j;
            for ( j=0; j<size; j++){
                if (a[j].second == key) {
                    a[j].first = element;
                    shiftUp(a, j);
                    break;
                }
            }

        }
    }
    return 0;
}