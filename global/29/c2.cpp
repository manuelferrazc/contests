#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool check(string s,int dir[]) {
    int a=0;
    for(char &c:s) {
        if(c=='0') {
            if(dir[a]) c='l';
            else c = 'r';
            a++;
        }
    }

    for(int i=0;i<s.size();i++) {
        if(s[i]=='1') {
            int q=0;
            if(i and s[i-1]=='r') q++;
            if(i<s.size()-1 and s[i+1]=='l') q++;
            if(q&1) return false;
        }
    }
    return true;
}

bool brute(string &s, int qtd, int dir[], int i) {
    if(i==qtd) return check(s,dir);

    dir[i] = 0;
    if(brute(s,qtd,dir,i+1)) return true;
    dir[i] = 1;
    if(brute(s,qtd,dir,i+1)) return true;
    return false;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int qtd=0;
    for(int i=0;i<n;i++) if(s[i]=='0') qtd++;

    if(qtd==0) {
        cout << "YES\n";
        return;
    }
    int dir[qtd];

    if(brute(s,qtd,dir,0)) cout << "YES\n";
    else cout << "NO\n";

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
