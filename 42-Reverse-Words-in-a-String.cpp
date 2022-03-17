#include<iostream>
using namespace std;

string reverseWords(string s) {
        list<string> lis;
        int n = s.length();
        string temp = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                if(temp.length() > 0){
                    lis.push_front(temp);
                }
                temp = "";
            }
            else
                temp.push_back(s[i]);
        }
        if(temp.length() > 0) lis.push_front(temp);
        string op = "";
        for(string i : lis){
            op.append(i);
            op.push_back(' ');
        }
        n = op.length()-1;
        if(n >= 0) op.erase(op.begin()+n);
        return op;
}

int main() {
    string s;
    char c;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        s.push_back(c);
    }
    cout << reverseWords(s);
}
