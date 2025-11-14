#include <iostream>;
using namespace std;

class node
{
public:
    int key;
    node *left;
    node *right;
    int height;
    node(int k)
    {
        key = k;
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

node *insertnode(node *root, int key)
{
    if (root == NULL)
        return new node(key);

    if (key < root->key)
        root->left = insertnode(root->left, key);
    else
        root->right = insertnode(root->right, key);

    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    int balance = getbalance(root);

    if (balance > 1 && key < root->left->key)
        return rightrotate(root);

    if (balance < -1 && key > root->right->key)
        return leftrotate(root);

    if (balance > 1 && key > root->left->key)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance < -1 && key < root->right->key)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    node *root = NULL;

    root = insertnode(root, 50);
    root = insertnode(root, 30);
    root = insertnode(root, 70);
    root = insertnode(root, 20);
    root = insertnode(root, 40);
    root = insertnode(root, 60);
    root = insertnode(root, 80);

    root = insertnode(root, 55);

    root = leftrotate(root);

    inorder(root);
}
