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

Node* findMin(Node* root){
        while(root && root->left)
            root = root->left;
        return root;
}

Node* deleteNode(Node* root, int key) {
        if(!root) return NULL;
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left && !root->right){
                delete root;
                root = NULL;
            }
            else if(!root->left){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(!root->right){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                Node* temp = findMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
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

    root = deleteNode(root, 50);
    printInorder(root);
}

