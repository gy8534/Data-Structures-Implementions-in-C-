#include <iostream>

using namespace std;

struct Bstnode
{
    int data;
    Bstnode *left, *right;

    Bstnode(int data_)
    {
        data = data_;
        left = right = NULL;
    }
};

Bstnode *Insert(Bstnode *root, int data)
{
    if (root == NULL)
        return new Bstnode(data);

    Bstnode *parent = NULL, *current = root;

    while (current != NULL)
    {
        parent = current;
        if (data <= current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (data <= parent->data)
    {
        parent->left = new Bstnode(data);
    }
    else
    {
        parent->right = new Bstnode(data);
    }
    return root;
}

int findMin(Bstnode *root){
    if (root==NULL){
        cout<<"Tree is Empty";
        return -1;
    }
    while (root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

int findMax(Bstnode *root){
    if (root == NULL){
        cout<<"Tree is empty";
        return -1;
    }
    while (root->right!=NULL){
        root = root->right;
    }
    return root->data;
}

int main()
{
    Bstnode *root = NULL;
    root = Insert(root, 100);
    Insert(root, 500);
    Insert(root, 10);
    Insert(root, 30);
    Insert(root, 40);
    cout<<"MIN: "<<findMin(root)<<"\n";
    cout<<"MAX: "<<findMax(root)<<"\n";
}