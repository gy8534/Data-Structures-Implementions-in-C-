#include <iostream>

using namespace std;

struct Bstnode{
    int data;
    Bstnode *left, *right;

    Bstnode(int data_){
        data = data_;
        left = right = NULL;
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

Bstnode* Insert(Bstnode* root, int data){
    if (root == NULL) return new Bstnode(data);

    Bstnode *parent=NULL, *current=root;

    while (current!=NULL){
        parent = current;
        if (data <= current->data){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (data <= parent->data){
        parent->left = new Bstnode(data);
    } else {
        parent->right = new Bstnode(data);
    }
    return root;
}

int main(){
    Bstnode *root = NULL;
    root = Insert(root, 15);
    Insert(root, 12);
    Insert(root, 14);
    inorder(root);
}