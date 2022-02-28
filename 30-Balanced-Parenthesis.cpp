#include<iostream>
#include<stack>
#define MAX_SIZE 100
using namespace std;

int A[MAX_SIZE];

int top = -1;

void push(int x){
    if(top == MAX_SIZE - 1){
        cout<<"Error : Stack Overflow\n";
        return;
    }
    A[++top] = x;
}

void pop(){
    if(top == -1){
        cout<<"Error : No element to pop\n";
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

int isEmpty(){
    if(top == -1)
        return 1;
    return 0;
}

bool checkExp(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            push(s[i]);
        else if(s[i] == '}' || s[i] == ']' || s[i] == ')'){
            if(s[i] == ')' && Top() == '(')
                pop();
            else if(s[i] == ']' && Top() == '[')
                pop();
            else if(s[i] == '}' && Top() == '{')
                pop();
            else
                return false;
        }
    }
    if(isEmpty() == 1)
        return true;
    return false;
}

int main(){
    string exp = "[(2@{0})]";
    checkExp(exp) == true ? cout<<"Balanced" : cout<<"Not Balanced";
}

