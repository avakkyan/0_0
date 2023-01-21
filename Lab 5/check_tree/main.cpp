#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node{
    int key = NULL;
    int left;
    int right;
};

vector <Node> BST;
bool check (int top, int min, int max){
    //int k=0;
    bool result = true;
    if (BST[top].key <= min or max <= BST[top].key){
        //result = false;
        cout << "NO";
        exit(0);
    }
    else {
        if (BST[top].left != -1)
            check(BST[top].left, min, BST[top].key);
        if (BST[top].right != -1)
            check(BST[top].right, BST[top].key, max);
    }
    return result;
}

int main() {
    int n, min, max;
    cin >> n;
    //vector <Node> BST;
    BST.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> BST[i].key;
        cin >> BST[i].left;
        BST[i].left--;
        cin >> BST[i].right;
        BST[i].right--;

    }
    if (n != 0) {
        if (check(0, -2147483646, 2147483646) == 1) {
            cout << "YES";
        }
    }
    else cout << "YES";
    return 0;
}