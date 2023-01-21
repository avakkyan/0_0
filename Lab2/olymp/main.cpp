#include <iostream>
using namespace std;
struct student{
    int id;
    int points;
};

int main() {
    int i,num_of_st;
    cin >> num_of_st;
    student *olympics = new student[num_of_st];
    for (i=0; i<num_of_st; i++) {
        cin >> olympics[i].id >> olympics[i].points;
    }
    int key1, key2;
    for (int j = 1; j < num_of_st; j++) {
        key1= olympics[j].points;
        i = j - 1;
        while ( i>=0 && olympics[i].points < key1) {
            swap(olympics[i],olympics[i+1]);
            i = i - 1;
        }

        }
    for (int j = 1; j < num_of_st; j++) {
        key1= olympics[j].points;
        key2= olympics[j].id;
        i = j - 1;
        while (i>=0 && ((olympics[i].points==olympics[i+1].points) && (olympics[i].id >olympics[i+1].id))){
            swap(olympics[i],olympics[i+1]);
            i--;
        }
    }
    for (i=0; i<num_of_st; i++){
        cout << olympics[i].id << " " << olympics[i].points;
        cout << "\n";
    }

    return 0;
}
