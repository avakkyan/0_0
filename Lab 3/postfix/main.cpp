#include <iostream>
using namespace std;
#include <vector>
#include <string>

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
    int pop()
    {
        int num1;
        node* temp;
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            num1=top->data;
            temp = top;
            top = top->link;
            free(temp);
        }
        return num1;
    }
    node *top;
};

int main() {
    std::string st;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    node_stack s;
    getline(cin, st);
    for (int i=0; i<st.size(); i++){
        if (isdigit(st[i])){
            s.push(st[i]-'0');
        }
        if (st[i] =='+'){
            int number1=s.pop();
            int number2 = s.pop();
            s.push(number1+number2);
        }
        if (st[i]=='-'){
            int number1=s.pop();
            int number2 = s.pop();
            s.push(number2-number1);
        }
        if (st[i]=='*'){
            int number1=s.pop();
            int number2 = s.pop();
            s.push(number2*number1);
        }
    }
    cout << s.pop();

    return 0;
}
