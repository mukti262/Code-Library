#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Tree{
    int val;
    Tree *left, *right;
};

Tree* newNode(int val){
    Tree* node = new Tree;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Inorder_to_fill_arr(Tree* root, vector<int>& arr){
    if(!root) return;
    Inorder_to_fill_arr(root->left, arr);
    arr.push_back(root->val);
    Inorder_to_fill_arr(root->right, arr);
}

void Inorder_to_update_val(Tree* root, vector<int>& arr, int& index){
    if(!root) return;
    Inorder_to_update_val(root->left, arr, index);
    root->val = arr[index]; index++;
    Inorder_to_update_val(root->right, arr, index);
}

void convertToBST(Tree* root, vector<int>& arr){
    Inorder_to_fill_arr(root, arr);
    sort(arr.begin(), arr.end());
    int index = 0;
    Inorder_to_update_val(root, arr, index);
}

void printInorder(Tree* root){
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    Tree* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->left->left->left = newNode(4);
    root->left->left->right = newNode(6);
    root->right->right->right = newNode(9);
    printInorder(root); cout << "\n";
    vector<int>arr;
    convertToBST(root, arr);
    printInorder(root); cout << "\n";
}
