#include <iostream>
using namespace std;

class node {
public:
    node(char n) {
        this->data = n;
        this->link = NULL;
    }

    char data;
    node *link;
};

class node_stack {
    node* top;
public:
    node_stack() {top = NULL;}
    void push(char data){
        node* temp = new node(data);
        //if !temp){
        //cout << "\nStack Overflow";
        //exit(1);
        //}
        temp->data = data;
        temp->link = top;
        top = temp;
    }
    void pop()
    {
        node* temp;
        if (top == NULL) {
            //cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            temp = top;
            top = top->link;
            free(temp);
        }
    }
    bool check(){
        if (top == nullptr){
            return 1;
        } else return 0;
    }
    char topel(){
        if (check()==1){
            return -1;
        }
        return top->data;

    }
};

int main() {
    string st;
    node_stack s;
    while(getline(cin,st)) {
        bool flag = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == '(' || st[i] == '[') {
                s.push(st[i]);
            }
            if (st[i] == ')') {
                if (s.topel() == '(')
                    s.pop();
                else {
                    cout << "NO" << '\n';
                    flag = 1;
                    break;
                }
            }

            if (st[i] == ']') {
                if (s.topel() == '[')
                    s.pop();
                else {
                    cout << "NO" << '\n';
                    flag = 1;
                    break;
                }
            }
        }
        if (s.check() && flag == 0)
            cout << "YES" << '\n';

        if (flag == 0 && !s.check()) {
            cout << "NO" << '\n';
        }
        while (!s.check())
            s.pop();
    }
    return 0;
}
