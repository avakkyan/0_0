#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    unsigned char height;
    Node* left;
    Node* right;
    Node(int k){
        key = k;
        left = 0;
        right = 0;
        height = 1;
    }
};

unsigned char height(Node* p){
    return p ? p->height : 0;
}

int v_balance(Node* p){
    if (p == NULL)
        return 0;
    return height(p->right) - height(p->left);
}

void fixheight(Node* p){
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

Node* rotateright(Node* p){
    if (p == NULL)
        return NULL;
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node* rotateleft(Node* q){
    if (q == NULL)
        return NULL;
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

int cnt = 0;
Node* balance(Node* p){
    if (p == NULL)
        return NULL;
    fixheight(p);
    if(v_balance(p) == 2){
        if(v_balance(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if(v_balance(p) == -2)
    {
        if( v_balance(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

Node* add(Node* p, int k){
    if(!p)
        return new Node(k);
    if(k < p->key)
        p->left = add(p->left, k);
    else
        p->right = add(p->right, k);
    return balance(p);
}

Node* boarderRght(Node* p) {
    if (p->right == nullptr)
        return p;
    return boarderRght(p->right);
}

Node* Del(int k, Node* p) {
    if (p == nullptr)
        return nullptr;
    if (k > p->key)
        p->right = Del(k, p->right);
    else if (k < p->key)
        p->left = Del(k, p->left);
    else{
        if (p->left == nullptr && p->right == nullptr)
            return nullptr;
        else
        if (p->left == nullptr){
            p = p->right;
            return balance(p);
        }
        else{
            Node *help = boarderRght(p->left);
            p->key = help->key;
            p->left = Del(help->key, p->left);
        }
    }
    return balance(p);
};


bool search(Node * root, int val){
    if (cnt > 0){
        if (root == NULL)
            return false;
        if (root->key == val)
            return true;
        if (val < root->key)
            return search(root->left, val);
        return search(root->right, val);
    }
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    Node * root = NULL;
    for (int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s;
        cin >> x;

        if (s == "A"){

            if (search(root, x)){
                cout << v_balance(root) << "\n";
                continue;
            }
            root = add(root, x);
            cnt++;
            cout << v_balance(root) << "\n";

        }

        if (s == "C")
            if (search(root, x))
                cout << "Y" << "\n";
            else
                cout << "N" << "\n";

        if (s == "D"){
            if (!search(root, x)){
                cout << v_balance(root) << "\n";
                continue;
            }
            root = Del(x, root);
            cout << v_balance(root) << "\n";
            cnt--;
        }
    }
    return 0;
}