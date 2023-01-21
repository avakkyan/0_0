#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int value;
    int left;
    int right;
};


int k = 0;

void insert(std::vector<Node> &BST,int mass[], int top) {
    if (BST[top].left != -1) {
        insert(BST,mass,BST[top].left);
    }
    if (BST[top].left == -1){
        if (BST[top].right == -1){
            if (BST[top].value == 0){
            }
        }
        BST[top].value = mass[k];
        k++;
    } else {
        if (BST[top].value == 0){
            BST[top].value = mass[k];
            k++;
        }
    }
    if (BST[top].right != -1) {
        insert(BST,mass,BST[top].right);
    }
}

int main() {
    int n;
    int arr[1000000];
    vector <Node> BST;
    cin >> n;
    BST.resize(n);
    for (int i = 0; i < n ; i++) {
        cin >> BST[i].left >> BST[i].right;
        BST[i].left--;
        BST[i].right--;
    }
    for (int i = 0; i < n + 100; i++){
        arr[i] = i + 1;
    }
    insert(BST,arr , 0);
    for (int i = 0; i < n; i++){
        cout << BST[i].value << ' ';
    }

    return 0;
}