#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
ll n,k;
string a,b;
ll mx=0;
set<char> m;

void count(set<char> &u) {
    ll ret = n*(n-1);
    ret>>=1;
    ret+=n;
    ll dif=0;
    for(ll i=1;i<=n;i++) {
        if(a[i-1]!=b[i-1] and not u.count(a[i-1])) {
            ret-=(i-dif)*(n-i+1);
            dif = i;
        }
    }
    mx=max(mx,ret);
}

void brute(set<char> &u,char c='a'-1) {
    if((ll)u.size()==k) {
        count(u);
        return;
    }
    if(c=='z') {
        count(u);
    }
    c++;
    for(;c<='z';c++) {
        if(m.count(c)) {
            u.insert(c);
            brute(u,c);
            u.erase(c);
        } else if(c=='z') count(u);
    }
}

void solve() {
    cin >> n >> k;
    cin >> a >> b;
    m.clear();
    mx=0;
    for(auto i:a) m.insert(i);
    
    set<char> s;
    brute(s);

    cout << mx << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
