#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i, x, y) for (ll i = x; i < y; i++)

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int x)
    {
        data = x;
    }
};

void RightView(Node *head, vector<int> &a)
{
    if (head == NULL)
        return;
    queue<Node *> q;
    q.push(head);
    q.push(NULL);
    int level = 1;
    a.push_back(head->data);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if (!q.empty())
                q.push(NULL);
            level++;
            if (!q.empty() && a.size() < level)
                a.push_back(q.front()->data);
        }

        else
        {
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            q.pop();
        }
    }
}

int main()
{
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->left->left->right = new Node(8);
    head->left->right->left = new Node(9);
    head->right->left->left = new Node(10);
    head->right->right->right = new Node(11);
    head->right->right->right->right = new Node(12);

    cout << "Right View: ";
    vector<int> rightv;
    RightView(head, rightv);
    for (int i = 0; i < rightv.size(); i++)
        cout << rightv[i] << " ";
    cout << endl;

    return 0;
}