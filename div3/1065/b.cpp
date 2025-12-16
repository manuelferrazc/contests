#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    int v[n];
    ll s = 0;
    int f=-1,l=-1;
    for(int i=0;i<n;i++) {
        cin >> i[v];
        if(v[i]!=-1) {
            l = i;
            if(f==-1) f = i;
        }
    }

    
    if(max(f,l)==-1) for(int i=0;i<n;i++) v[i] = 0;
    else if(f or l<n-1) {
        for(int i=0;i<n;i++) v[i] = (v[i]>=0?v[i]:0);
        for(int i=1;i<n;i++) s+=v[i]-v[i-1];
        if(f) v[0] = s;
        else v[n-1] = -s;
        s=0;
    } else {
        for(int i=0;i<n;i++) v[i] = (v[i]>=0?v[i]:0);
        for(int i=1;i<n;i++) s+=v[i]-v[i-1];
    }

    cout << abs(s) << '\n';
    for(int i=0;i<n;i++) cout << i[v] << ' ';
    cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
