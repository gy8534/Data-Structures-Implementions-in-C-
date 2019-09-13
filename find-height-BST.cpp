#include <iostream>
#include <algorithm>
using namespace std;

struct BstNode{
    int data;
    BstNode *left, *right;

    BstNode(int data_){
        data = data_;
        left = right = NULL;
    }
};

BstNode *Insert(BstNode *root, int data){
    if (root == NULL) return new BstNode(data);
    else if (data<=root->data) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}

int findHeight(BstNode *root){
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight)+1;
}

int main(){
    BstNode *root = NULL;
    root = Insert(root, 100);
    Insert(root, 20);
    Insert(root, 500);
    Insert(root, 10);
    Insert(root, 30);
    cout<<"Height of the tree is: "<<findHeight(root);
}