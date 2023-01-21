#include <iostream>
using namespace std;
#include <vector>

struct Node{
    int data;
    vector<int> del;
    struct Node *next; // уаказатель на след узел
};
struct Node* head=NULL;
struct Node* tail=NULL;
struct Node* temp;

void Insert (){
    int val;
    cin>>val;
    if (tail == NULL){
        tail = (struct Node *)malloc(sizeof(struct Node));
        tail->next = NULL;
        tail->data = val;
        head = tail;
    }
    else {
        temp = (struct Node *)malloc(sizeof (struct Node));
        tail->next=temp;
        temp->data = val;
        temp->next=NULL;
        tail=temp;
    }
}
void Delete() {
    vector<int> del;
    temp = head;
    if (head == NULL) {
        return;
    } else if (temp->next != NULL) {
        temp = temp->next;
        del.push_back(head->data);
        free(head);
        head = temp;
    } else {
        del.push_back(head->data);
        free(head);
        head = NULL;
        tail = NULL;
    }
    for (int i=0; i<del.size(); i++)
        cout << del[i] << "\n";
}
void Display() {
    temp = head;
    if ((head == NULL) && (tail == NULL)) {
        //cout<<"Queue is empty"<<endl;
        return;
    }
    //cout<<"Queue elements are: ";
    while (temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int num_of_acts, number;
    char move;
    cin >> num_of_acts;
    for (int i=0; i<num_of_acts; i++){
        cin>>move;
        if (move == '+'){
            Insert();
        }
        if (move == '-'){
            Delete();
        }
    }
    return 0;
}

