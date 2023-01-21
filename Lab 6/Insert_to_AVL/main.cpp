#include <bits/stdc++.h>
using namespace std;

struct InNode {
    int key;
    int left;
    int right;
};

struct Node {
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key) : key(key) {
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

Node *root = nullptr;
int Size = 0;

int getHeight(Node *node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

Node *RecursiveBuild(vector<InNode> &vec, int i) {
    if (i < 0 || vec.size() == 0)
        return nullptr;
    auto newNode = new Node(vec[i].key);
    Size++;
    newNode->left = RecursiveBuild(vec, vec[i].left);
    newNode->right = RecursiveBuild(vec, vec[i].right);
    newNode->height = max(getHeight(newNode->left), getHeight(newNode->right)) + 1;
    return newNode;
}


void CorrectHeight(Node *node) {
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int GetBalance(Node *node) {
    return getHeight(node->right) - getHeight(node->left);
}

Node *rotat(Node *node, bool is_turn_left) {
    Node *tmp = is_turn_left ? node->right : node->left;
    if (is_turn_left) {
        node->right = tmp->left;
        tmp->left = node;
    } else {
        node->left = tmp->right;
        tmp->right = node;
    }
    CorrectHeight(node);
    CorrectHeight(tmp);
    return tmp;
}

Node *rotateRight(Node *node) {
    return rotat(node, false);
}


Node *rotateLeft(Node *node) {
    return rotat(node, true);
}

Node *Balance(Node *node) {
    if (GetBalance(node) > 1) {
        if (GetBalance(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (GetBalance(node) < -1) {
        if (GetBalance(node->left) > 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}


Node *ReursiveInsert(int key, Node *now) {
    if (now == nullptr) {
        return new Node(key);
    }
    if (key > now->key) {
        now->right = ReursiveInsert(key, now->right);
    } else {
        now->left = ReursiveInsert(key, now->left);
    }
    CorrectHeight(now);
    return Balance(now);
}



void Build(vector<InNode> &G) {
    root = RecursiveBuild(G, 0);
}

void Insert(int key) {
    root = ReursiveInsert(key, root);
    Size++;
}

void Draw() {
    queue<Node *> q;
    q.push(root);
    int line = 1;
    cout << Size << endl;
    while (!q.empty()) {
        Node *node = q.front();
        q.pop();
        int left = 0, right = 0;
        if (node->left != nullptr) {
            q.push(node->left);
            left = ++line;
        }
        if (node->right != nullptr) {
            q.push(node->right);
            right = ++line;
        }
        cout << node->key << " " << left << " " << right << "\n";
    }
}


int main() {
    int n;
    cin >> n;

    vector<InNode> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].key >> nodes[i].left >> nodes[i].right;
        nodes[i].left--;
        nodes[i].right--;
    }
    Build(nodes);
    int c;
    cin >> c;
    Insert(c);
    Draw();
    return 0;
}