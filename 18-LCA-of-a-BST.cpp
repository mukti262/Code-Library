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

Node* solve(Node* root, Node* p, Node* q) {
        if(!root) return root;
        if(p-> val < root->val && q->val < root->val)
            return solve(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return solve(root->right, p, q);
        return root;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root) return root;
        if(p->val > q->val){
            Node* temp = p;
            p = q;
            q = temp;
        }
        return solve(root, p, q);
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
    cout << lowestCommonAncestor(root, root->left, root)->val;
}

