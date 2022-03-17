#include<iostream>
using namespace std;

unordered_map<string, bool> m;
bool isScramble(string s1, string s2) {
        if(s1.compare(s2) == 0)
            return true;
        if(s1.length() <= 1)
            return false;
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        if(m.find(key) != m.end())
            return m[key];
        int n = s1.length();
        bool flag = false;
        for(int i = 1; i <= n-1; i++){
            if((isScramble(s1.substr(0, i), s2.substr(n-i, i)) &&
               isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) ||
               (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
               isScramble(s1.substr(i, n-i), s2.substr(i, n-1)))){
                flag = true;
                break;
            }
        }
                return m[key] = flag;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << isScramble(s1, s2);
}
