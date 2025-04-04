#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n),b(n),c(n);
    for(int i=n-1;i>=0;i--) cin >> a[i];
    for(int i=n-1;i>=0;i--) cin >> b[i];
    for(int i=n-1;i>=0;i--) cin >> c[i];

    int act=0;
    while(act!=x and a.size()) {
        if(a.back()&(~x)) a.clear();
        else {
            act|=a.back();
            a.pop_back();
        }
    }
    
    while(act!=x and b.size()) {
        if(b.back()&(~x)) b.clear();
        else {
            act|=b.back();
            b.pop_back();
        }
    }
    
    while(act!=x and c.size()) {
        if(c.back()&(~x)) c.clear();
        else {
            act|=c.back();
            c.pop_back();
        }
    }

    if(x==act) cout << "yeS\n";
    else cout << "nO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
