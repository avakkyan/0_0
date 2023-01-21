#include <iostream>
using namespace std;
#include <vector>
#include <string>

class node {
public:
    node(int n) {
        this->data = n;
        this->link = NULL;
        this->max = NULL;
    }
    int data;
    int max;
    node *link;
};

class node_stack {
    node* top;
public:
    node_stack() {top = NULL;}
    bool isEmpty(){
        return !top;
    }
    void push(int data) {
        node *temp = new node(data);
        if (isEmpty()) {
            temp->data = data;
            temp->max = data;
            temp->link = NULL;
            top = temp;
        } else {
            temp->link = temp;
            temp->link = nullptr;
            temp->data = data;
            if (top->max < data) {
                temp->max = data;
            } else
                temp->max = top->max;
            temp->link = top;
            top = temp;
        }
    }
    void pop()
    {
        node* temp;
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            temp = top;
            top = top->link;
            free(temp);
        }
    }
    int topel(){
        return top->data;
    }
    int maximum(){
        return top->max;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    std::string st;
    int num_of_acts, number;
    node_stack s;
    cin>>num_of_acts;
    for (int i=0; i<num_of_acts; i++) {
        cin >> st;
        if (st[0] == '+') {
            cin >> number;
            s.push(number);
        }
        else if (st[0] == '-') {
            s.pop();
        }
        else if (st[0] == 'm') {
            cout << s.maximum() << '\n';
        }
    }
    return 0;
}
