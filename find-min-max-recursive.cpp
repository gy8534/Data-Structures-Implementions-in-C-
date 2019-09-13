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

int findMax(Bstnode *root){
    if (root==NULL){
        cout<<"Tree is empty";
        return -1;
    }else if (root->right == NULL){
        return root->data;
    }
    return findMax(root->right);
}

int findMin(Bstnode *root){
    if (root == NULL){
        cout<<"Tree is empty";
        return -1;
    } else if (root->left==NULL){
        return root->data;
    }
    return findMin(root->left);
}

int main()
{
    Bstnode *root = NULL;
    int ar[] = {50, 20, 30, 70, 80};
    for (int i = 0; i < 5; i++)
    {
        root = Insert(root, ar[i]);
    }
    cout<<"Min: "<<findMin(root)<<"\n";
    cout<<"Max: "<<findMax(root);
}