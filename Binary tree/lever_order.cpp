#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void printLevelOrder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;
    // stack<Node *> q; you can use this way to print level from right to left, but it will be slower than the queue
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        // Node *curr = q.top(); you can use this way to print level from right
        q.pop();

        cout << curr->value << " ";

        // you can swap this codition to get right-to-left level order but if u use stack then this condtion will applicable for right-to-left
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal of binary tree is \n";
    printLevelOrder(root);

    return 0;
}