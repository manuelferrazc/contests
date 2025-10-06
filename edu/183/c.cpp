#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(int *sp, int l, int r) {
    if(l==0) return sp[r];
    return sp[r]-sp[l-1];
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    int a=0,b=0;
    int ans = n;

    for(int i=0;i<n;i++) {
        if(s[i]=='a') a++;
        else b++;

        if(a==b) ans = n-i-1;
    }

    a=0;
    b=0;

    for(int i=n-1;i>=0;i--) {
        if(s[i]=='a') a++;
        else b++;

        if(a==b) ans = min(ans,i);
    }

    int qa[n],qb[n];
    if(s[0]=='a') {
        qa[0] = 1;
        qb[0] = 0;
    } else {
        qa[0] = 0;
        qb[0] = 1;
    }

    for(int i=1;i<n;i++) {
        qa[i] = qa[i-1];
        qb[i] = qb[i-1];
        if(s[i]=='a') qa[i]++;
        else qb[i]++;
    }

    map<int,vector<int>> suf;
    a=0;
    for(int i=n-1;i;i--) {
        if(s[i]=='a') a++;
        else a--;

        suf[a].push_back(i);
    }

    for(int i=0;i<n-1;i++) {
        int qtdn = get(qa,i+1,n-1)-get(qb,i+1,n-1);
        if(suf.count(qtdn)) {
            suf[qtdn].pop_back();
            if(suf[qtdn].empty()) suf.erase(qtdn);

        }

        int qtd = get(qb,0,i)-get(qa,0,i);

        if(suf.count(qtd)) {
            // cout << i << ' ' << qtd << ' ' << suf[qtd].back() << '\n';
            ans = min(ans,suf[qtd].back()-i-1);
        }
    }

    if(ans==n) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
