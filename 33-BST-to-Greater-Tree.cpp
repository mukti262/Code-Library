#include<iostream>
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

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val <<" ";
    inorder(root->right);
}

int sum = 0;

Node* convertBST(Node* root) {
        if (root) {
            root->right = convertBST(root->right);
            root->val += sum;
            sum = root->val;
            root->left = convertBST(root->left);
        }
        return root;
}

int main(){
    Node* root = new Node;
    root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 13);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 12);
    root = insertNode(root, 15);

    root = convertBST(root);
    inorder(root);

    return 1;
}

