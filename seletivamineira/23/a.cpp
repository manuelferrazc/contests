#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    string b,f,r;
    cin >> b >> f >> r;

    if(b[0]=='r') {
        if(f[0]=='r') {
            if(r[0]=='p') cout << 'S';
            else cout << '?';
        } else if(f[0]=='p') {
            if(r[0]=='r') cout << 'M';
            else cout << '?';
        } else {
            if(r[0]=='s') cout << 'F';
            else cout << '?';
        }
    } else if(b[0]=='p') {
        if(f[0]=='r') {
            if(r[0]=='r') cout << 'F';
            else cout << '?';
        } else if(f[0]=='p') {
            if(r[0]=='s') cout << 'S';
            else cout << '?';
        } else {
            if(r[0]=='p') cout << 'M';
            else cout << '?';
        }
    } else {// s
        if(f[0]=='r') { // s r
            if(r[0]=='s') cout << 'M';
            else cout << '?';
        } else if(f[0]=='p') { // s p
            if(r[0]=='p') cout << 'F';
            else cout << '?';
        } else { // s s
            if(r[0]=='r') cout << 'S';
            else cout << '?';
        }
    }
    cout << '\n';
    return 0;
}
