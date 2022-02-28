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

int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
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
    cout << maxDepth(root);
}

