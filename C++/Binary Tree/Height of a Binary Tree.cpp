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

int height(Node *head)
{
    if (head == NULL)
        return 0;
    int lh = height(head->left);
    int rh = height(head->right);
    return max(lh, rh) + 1;
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

    cout << "\nHeight: ";
    int h = height(head);
    cout << h << '\n';

    return 0;
}