#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node{
    string key;
    Node *left;
    Node *right;
    Node *parent;
};
class BST{
public:
    Node * root;
    BST(): root(nullptr)  {}

    void insert(string x){
        Node *ins = root; Node *prev = nullptr;
        while (ins != nullptr){
            if (ins->key == x){
                return;
            }
            if (ins->key < x){
                prev = ins;
                ins = ins->right;
            }
            else {
                prev = ins;
                ins = ins->left;
            }
        }
        ins = new Node;
        ins->key = x;
        ins->left = nullptr;
        ins->right = nullptr;
        if (prev == nullptr) {
            ins->parent = nullptr;
            root = ins;
        }
        else {
            ins->parent = prev;
            if (x > prev->key) {
                prev->right = ins;
            }
            else prev->left = ins;
        }
    }
    Node* search (string x) {
        Node *temp = root;
        while (temp != nullptr) {
            if (x == temp->key) {
                return temp;
            }
            if (x < temp->key) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return nullptr;
    }
    Node *next(string top){
        Node *ins = root; Node *temp = nullptr;
        while (ins != nullptr && ins->key != top) {
            if (top < ins->key) {
                temp = ins;
                ins = ins->left;
            } else {
                temp = ins;
                ins = ins->right;
            }
        }
        if (ins== nullptr){
            ins = new Node;
            ins->parent = temp;
            ins->key = top;
            ins->left = nullptr;
            ins->right = nullptr;
            temp = ins;
        }
        else temp = ins;
        if (temp->right != nullptr) {
            temp = temp->right;
            while (temp->left != nullptr)
                temp = temp->left;
            return temp;
        }
        else {
            while (temp->parent != nullptr) {
                temp = temp->parent;
                if (temp->key > top) {
                    return temp;
                }
            }
            return nullptr;
        }
    }
    void prev(string top) {
        Node *ins = root;
        Node *temp = nullptr;
        while (ins != nullptr && ins->key != top) {
            if (top < ins->key) {
                temp = ins;
                ins = ins->left;
            } else {
                temp = ins;
                ins = ins->right;
            }
        }
        if (ins == nullptr) {
            ins = new Node;
            ins->parent = temp;
            ins->key = top;
            ins->left = nullptr;
            ins->right = nullptr;
            temp = ins;
        }
        else temp = ins;
        if (temp->left != nullptr) {
            temp = temp->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            cout << temp->key << '\n';
            return;
        } else {
            while (temp->parent != nullptr) {
                temp = temp->parent;
                if (temp->key < top) {
                    cout << temp->key << '\n';
                    return;
                }
            }
            cout << "none"<< '\n';
        }
    }
    void dell(string top){
        Node *temp = search(top);
        if (temp == nullptr){
            return;
        }
        if (temp->left == nullptr && temp->right == nullptr) {
            if (temp->parent == nullptr) {
                root = nullptr;
                delete temp;
                return;
            }
            if (temp->parent->left == temp) {
                temp->parent->left = nullptr;
                delete temp;
            }
            if (temp->parent->right == temp) {
                temp->parent->right = nullptr;
                delete temp;
            }
            return;
        }
        if (temp->left == nullptr  || temp->right == nullptr) {
            if (temp->left == nullptr) {
                if (temp->parent == nullptr) {
                    temp->right->parent = nullptr;
                    root = temp->right;
                    delete temp;
                    return;
                }
                if (temp->parent->left == temp) {
                    temp->parent->left = temp->right;
                }
                else
                    temp->parent->right = temp->right;
                temp->right->parent = temp->parent;
                delete temp;
                return;
            }
            if (temp->right == nullptr) {
                if (temp->parent == nullptr) {
                    temp->left->parent = nullptr;
                    root = temp->left;
                    delete temp;
                    return;
                }
                if (temp->parent->left == temp) {
                    temp->parent->left = temp->left;
                }
                else {
                    temp->parent->right = temp->left;
                }
                temp->left->parent = temp->parent;
                delete temp;
                return;
            }
        }

        Node *next_elem = next(top);
        temp->key = next_elem->key;
        if (next_elem->parent->left == next_elem) {
            next_elem->parent->left = next_elem->right;
            if (next_elem->right != nullptr)
                next_elem->right->parent = next_elem->parent;
        }
        else {
            next_elem->parent->right = next_elem->right;
            if (next_elem->right != nullptr)
                next_elem->right->parent = next_elem->parent;
        }
        delete next_elem;
    }
};
int main() {
    int n;
    int points_1=0;
    int points_2=0;
    int points_3=0;
    BST BST1;
    BST BST2;
    BST BST3;

    vector <string> friend1;
    vector <string> friend2;
    vector <string> friend3;
    cin >> n;

    friend1.resize(n);
    friend2.resize(n);
    friend3.resize(n);

    for (int i = 0; i<n; i++){
        cin >> friend1[i];
        BST1.insert(friend1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> friend2[i];
        BST2.insert(friend2[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> friend3[i];
        BST3.insert(friend3[i]);
    }
    for (int i=0; i<n; i++){
        Node *otv1 = BST2.search(friend1[i]);
        Node *otv2 = BST3.search(friend1[i]);
        if (otv1 == nullptr && otv2 == nullptr) {
            points_1 += 3;
        }
        if (otv1 != nullptr && otv2 != nullptr) {
            points_1 += 0;
            continue ;
        }
        if (otv1 != nullptr || otv2 != nullptr) {
            points_1 += 1;
        }


    }
    for (int i = 0; i < n; i++){
        Node *otv1 = BST1.search(friend2[i]);
        Node *otv2 = BST3.search(friend2[i]);
        if (otv1 == nullptr && otv2 == nullptr) {
            points_2 += 3;
        }
        if (otv1 != nullptr && otv2 != nullptr) {
            points_2 += 0;
            continue ;
        }
        if (otv1 != nullptr || otv2 != nullptr) {
            points_2 += 1;
        }

    }
    for (int i = 0; i < n; i++){
        Node *otv1 = BST2.search(friend3[i]);
        Node *otv2 = BST1.search(friend3[i]);
        if (otv1 == nullptr && otv2 == nullptr) {
            points_3 += 3;
        }
        if (otv1 != nullptr && otv2 != nullptr) {
            points_3 += 0;
            continue ;
        }
        if (otv1 != nullptr || otv2 != nullptr) {
            points_3 += 1;
        }

    }
    cout << points_1<< ' ';
    cout << points_2 << ' ';
    cout<< points_3;
    return 0;
}

