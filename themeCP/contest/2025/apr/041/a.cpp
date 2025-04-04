#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string a;

bool check(string &s) {
    int pa=0;
    for(char c:s) {
        if(c=='(') pa++;
        else {
            if(pa==0) return false;
            pa--;
        }
    }
    
    return pa==0;
}

void replace(string &s, char t, char n) {
    for(ull i=0;i<a.size();i++) if(a[i]==t) s[i] = n;
}

void solve() {
    cin >> a;
    string b = a;
    
    replace(b,'A','(');
    replace(b,'B','(');
    replace(b,'C',')');
    // A B      C
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    replace(b,'B',')');
    // A        B C
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    replace(b,'C','(');
    // A C       B
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    replace(b,'A',')');
    // C      A B
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    replace(b,'B','(');
    // C B     A
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    replace(b,'C',')');
    // B      C A
    if(check(b)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
