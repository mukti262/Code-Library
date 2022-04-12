#include<iostream>
#include<vector>
using namespace std;

string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        int carry = 0;
        string res = "";
        while(m > 0 && n > 0) {
            if(a[m-1] == '1' && b[n-1] == '1') {
                if(carry == 1) {
                    res.push_back('1');
                    carry = 1;
                } else {
                    res.push_back('0');
                    carry = 1;
                }
            } else if(a[m-1] == '0' && b[n-1] == '0') {
                if(carry == 1) {
                    res.push_back('1');
                    carry = 0;
                } else {
                    res.push_back('0');
                    carry = 0;
                }
            } else {
                if(carry == 1) {
                    res.push_back('0');
                    carry = 1;
                } else {
                    res.push_back('1');
                    carry = 0;
                }
            }
            m--; n--;
        }
        while(m > 0) {
            if(a[m-1] == '1' && carry == 1) {
                res.push_back('0');
                carry = 1;
            } else if(a[m-1] == '0' && carry == 0) {
                res.push_back('0');
            } else {
                res.push_back('1');
                carry = 0;
            }
            m--;
        }
        while(n > 0) {
            if(b[n-1] == '1' && carry == 1) {
                res.push_back('0');
                carry = 1;
            } else if(b[n-1] == '0' && carry == 0) {
                res.push_back('0');
            } else {
                res.push_back('1');
                carry = 0;
            }
            n--;
        }
        if(carry == 1)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b);
}
