#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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

vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int n = q.size();
            while(n--){
            Node* node = q.front();
            level.push_back(node->val);
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
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
    vector<vector<int>>ans = levelOrder(root);
    for(auto i: ans) {
        cout << "[";
        for(int j: i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}

