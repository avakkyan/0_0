#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    int left;
    int right;
    int Height=1;
    int balance=0;
};
vector<Node> BST;
int H(int top){

    if (BST[top].left >= 0) {
        H(BST[top].left);
    }
    if (BST[top].right >= 0){
        H(BST[top].right);
    }
    if (BST[top].right != -1 || BST[top].left != -1){
        int l_h, r_h;
        if (BST[top].left >= 0)
            l_h = BST[BST[top].left].Height;
        else l_h = 0;
        if (BST[top].right >= 0)
            r_h = BST[BST[top].right].Height;
        else r_h = 0;
        BST[top].Height = max(l_h,r_h)+1;
        BST[top].balance = r_h - l_h;
    }
    return BST[top].balance;
}

int main() {
    int n;
    cin >> n;
    BST.resize(n);
    for (int i=0; i<n; i++){
        cin >> BST[i].key;
        cin >> BST[i].left;
        BST[i].left--;
        cin >> BST[i].right;
        BST[i].right--;
    }
    H(0);
    for (int i=0; i<n ; i++) {
        cout << BST[i].balance << '\n';
    }
    return 0;
}