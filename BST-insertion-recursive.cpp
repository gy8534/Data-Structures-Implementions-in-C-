#include <iostream>

using namespace std;

struct Bstnode
{
    int data;
    Bstnode *left, *right;

    Bstnode(int data_)
    {
        data = data_;
        left = NULL;
        right = NULL;
    }
};

void inorder(Bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

Bstnode *Insert(Bstnode *root, int data)
{
    if (root == NULL)
        return new Bstnode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main()
{
    Bstnode *root = NULL;
    int ar[] = {50, 20, 30, 70, 80};
    for (int i = 0; i < 5; i++)
    {
        root = Insert(root, ar[i]);
    }
    inorder(root);
}