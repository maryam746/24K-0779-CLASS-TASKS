#include <iostream>
using namespace std;

class node
{
public:
    int roll;
    node *left;
    node *right;
    int height;
    node(int r)
    {
        roll = r;
        left = right = NULL;
        height = 1;
    }
};

int getheight(node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int getbalance(node *n)
{
    if (n == NULL)
        return 0;
    return getheight(n->left) - getheight(n->right);
}

node *rightrotate(node *y)
{
    node *x = y->left;
    node *t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    return x;
}

node *leftrotate(node *x)
{
    node *y = x->right;
    node *t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return y;
}

node *insertnode(node *root, int roll)
{
    if (root == NULL)
        return new node(roll);
    if (roll < root->roll)
        root->left = insertnode(root->left, roll);
    else
        root->right = insertnode(root->right, roll);
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    int balance = getbalance(root);
    if (balance > 1 && roll < root->left->roll)
        return rightrotate(root);
    if (balance < -1 && roll > root->right->roll)
        return leftrotate(root);
    if (balance > 1 && roll > root->left->roll)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (balance < -1 && roll < root->right->roll)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->roll << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void printbalance(node *root)
{
    if (root != NULL)
    {
        printbalance(root->left);
        cout << "student roll " << root->roll << " balance " << getbalance(root) << endl;
        printbalance(root->right);
    }
}

int main()
{
    node *root = NULL;
    root = insertnode(root, 10);
    root = insertnode(root, 20);
    root = insertnode(root, 30);
    root = insertnode(root, 40);
    root = insertnode(root, 50);

    root = insertnode(root, 15);

    root = leftrotate(root);

    cout << "preorder of final avl tree: ";
    preorder(root);
    cout << endl;

    cout << "balance factors: " << endl;
    printbalance(root);

    cout << "height of tree: " << getheight(root) << endl;
}
