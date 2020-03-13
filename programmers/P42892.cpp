#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num;
    int x, y;
    Node* left;
    Node* right;
};

bool comp(Node& a, Node& b) {
    if (a.y == b.y) return a.x < b.x;
    return b.y < a.y;
}

void insert(Node* parent, Node* child) {
    if (parent->x > child->x) {
        if (parent->left == NULL) parent->left = child;
        else insert(parent->left, child);
    }
    else {
        if (parent->right == NULL) parent->right = child;
        else insert(parent->right, child);
    }
}

void preorder(Node* node, vector<int>& list) {
    if (node == NULL) return;

    list.push_back(node->num);

    preorder(node->left, list);
    preorder(node->right, list);
}

void postorder(Node* node, vector<int>& list) {
    if (node == NULL) return;

    postorder(node->left, list);
    postorder(node->right, list);

    list.push_back(node->num);
}

vector<vector<int> > solution(vector<vector<int> > nodeinfo) {
    vector<vector<int> > answer(2);

    vector<Node> nodes;
    for (int i = 0; i < nodeinfo.size(); i++)
        nodes.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1]});

    sort(nodes.begin(), nodes.end(), comp);

    Node* root = &nodes[0];
    for (int i = 1; i < nodes.size(); i++) insert(root, &nodes[i]);

    preorder(root, answer[0]);
    postorder(root, answer[1]);

    return answer;
}