#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    int left;
    int right;
};
int max_h=0;
int height=1;
vector <Node> BST;

void H(int top){
        if (height > max_h){
            max_h = height;
        }
        if (top >= 0 && BST[top].left >= 0) {
            height++;
            if (height > max_h) {
                max_h = height;
            }
            H(BST[top].left);
        }
        if (top >= 0 && BST[top].right >= 0){
            height ++;
            if (height > max_h) {
                max_h = height;
            }
            H(BST[top].right);
        }
    height--;
}

int main() {
    int n;
    cin>>n;
    //vector <Node> BST;
    BST.resize(n);
    for (int i=0; i<n; i++) {
        cin >> BST[i].key;
        cin >> BST[i].left;
        BST[i].left--;
        cin >> BST[i].right;
        BST[i].right--;

    }
    if(n == 0) {
        max_h=0;
    }
    else {
        H(0);
    }
     cout << max_h;
        return 0;
    }