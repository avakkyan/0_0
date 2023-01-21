#include <iostream>
using namespace std;
#include <vector>

class node {
public:
    node(int n) {
        this->data = n;
        this->link = NULL;
    }

    int data;
    node *link;
};

class node_stack {
    node* top;
public:
    node_stack() {top = NULL;}
    void push(int data){
        node* temp = new node(data);
        if (!temp){
            cout << "\nStack Overflow";
            exit(1);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }
    void pop()
    {
        vector<int> del;
        node* temp;
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            del.push_back(top->data);
            temp = top;
            top = top->link;
            free(temp);
        }
        for (int i=0; i<del.size(); i++)
            cout << del[i] << "\n";
    }
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    node_stack s;
    int num_of_acts, number;
    char move;
    cin >> num_of_acts;
    for (int i=0; i<num_of_acts; i++){
        cin>>move;
        if (move == '+'){
            cin >> number;
            s.push(number);
        }
        if (move == '-'){
            s.pop();
        }
    }

    return 0;
}
