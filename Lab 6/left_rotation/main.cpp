#include<bits/stdc++.h>
using namespace std;
int n;

struct node{
    int data;
    int left;
    int right;
};

vector<node> vec;
vector<int> height;

int MakeHeight(int v, int h){
    if(v < 0) return 0;
    height[v] = max(MakeHeight(vec[v].left, h), MakeHeight(vec[v].right, h)) + 1;
    return height[v];
}

int GetHeight(int v){
    if(v < 0) return 0;
    return height[v];
}
void FixHeight(int v){
    height[v] = max(GetHeight(vec[v].left), GetHeight(vec[v].right)) + 1;
}
void EnterNode(node* p) {
    vec.push_back(*p);
    height.push_back(0);
}

void GoHeight(){
    MakeHeight(0, 0);
}
int rotateleft(int v){
    int b = vec[v].right;
    vec[v].right = vec[b].left;
    vec[b].left = v;
    FixHeight(v);
    FixHeight(b);
    return b;
}

int rotateright(int v){
    int b = vec[v].left;
    vec[v].left = vec[b].right;
    vec[b].right = v;
    FixHeight(v);
    FixHeight(b);
    return b;
}
int bigTurnLeft(int v){
    vec[v].right = rotateright(vec[v].right);
    return rotateleft(v);
}

int rotat(int v){
    int right = vec[v].right;
    int LeftLeaveHeight = GetHeight(vec[right].left);
    int RightLeaveHeight = GetHeight(vec[right].right);
    if(RightLeaveHeight - LeftLeaveHeight < 0){
        return bigTurnLeft(v);
    }
    return rotateleft(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    node p;

    for(int i = 0; i < n; i++){
        cin >> p.data >> p.left >> p.right;
        p.left--;
        p.right--;
        EnterNode(&p);
    }
    GoHeight();
    int newRoot = rotat(0);
    cout << vec.size() << "\n";
    queue<int> q;

    q.push(newRoot);
    int line = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int l = 0, r = 0;
        if(vec[v].left >= 0){
            q.push(vec[v].left);
            l = ++line;
        }
        if(vec[v].right >= 0){
            q.push(vec[v].right);
            r = ++line;
        }
        cout << vec[v].data << " " << (l) << " " << (r) << endl;
    }
    return 0;
}