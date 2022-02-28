#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL)
        return newNode;
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void print(Node* root){
    if(root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

void arrBT(int* A, Node* root, int i){
    if(root != NULL){
        A[i] = root->data;
        arrBT(A, root->left, 2*i + 1);
        arrBT(A, root->right, 2*i + 2);
    }
}
int main(){
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 13);
    root = insert(root, 15);
    root = insert(root, 11);
    print(root);
    int A[10];
    for(int i = 0; i < 10; i++)
        A[i] = 0;
    cout << endl;
    arrBT(A, root, 0);
    for(int j = 0; j < 7; j++)
        cout << A[j] << " ";
}

