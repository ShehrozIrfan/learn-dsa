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

void InOrder(Node *head, vector<int> &a)
{
    if (head == NULL)
        return;
    InOrder(head->left, a);
    a.push_back(head->data);
    InOrder(head->right, a);
    return;
}

void ChildrenSumProperty(Node *head)
{
    if (head == NULL)
        return;
    if (head->left && head->right && head->left->data + head->right->data <= head->data)
    {
        head->left->data = head->data;
        head->right->data = head->data;
        ChildrenSumProperty(head->left);
        ChildrenSumProperty(head->right);
        head->data = head->left->data + head->right->data;
        return;
    }
    else if (head->right && !head->left && head->right->data <= head->data)
    {
        head->right->data = head->data;
        ChildrenSumProperty(head->right);
        head->data = head->right->data;
    }
    else if (head->right && !head->left && head->right->data > head->data)
    {
        ChildrenSumProperty(head->right);
        head->data = head->right->data;
    }
    else if (head->left && !head->right && head->left->data <= head->data)
    {
        head->left->data = head->data;
        ChildrenSumProperty(head->left);
        head->data = head->left->data;
    }
    else if (head->left && !head->right && head->left->data > head->data)
    {
        ChildrenSumProperty(head->left);
        head->data = head->left->data;
    }
    else if (head->left && head->right)
    {
        head->data = head->left->data + head->right->data;
        ChildrenSumProperty(head->left);
        ChildrenSumProperty(head->right);
        head->data = head->left->data + head->right->data;
    }
    return;
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

    vector<int> prein, newin;

    cout << "Previous Inorder: ";
    InOrder(head, prein);
    for (int i = 0; i < prein.size(); i++)
    {
        cout << prein[i] << ' ';
    }
    cout << '\n';

    cout << "\nChildren Sum Property: Applied\n";
    ChildrenSumProperty(head);

    cout << "\nLater InOrder: ";
    InOrder(head, newin);
    for (int i = 0; i < newin.size(); i++)
    {
        cout << newin[i] << ' ';
    }
    cout << '\n';

    return 0;
}