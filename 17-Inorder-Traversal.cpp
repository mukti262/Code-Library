#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* insertUtil(int val){
    Node* root = new Node;
    root->val = val;
    root->left = root->right = NULL;
    return root;
}

Node* insertNode(Node* root, int val){
    if(!root)
       return insertUtil(val);
    if(val <= root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

void printInorder(Node* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main(){
    Node* root = new Node;
    root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 50);
    root = insertNode(root, 1);
    root = insertNode(root, 40);
    root = insertNode(root, 100);
    printInorder(root);
}
