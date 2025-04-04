#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool brute(vector<int> &v, int x) {
    vector<int> b;
    for(int i=0;i<x-1;i++) b.push_back(gcd(v[i],v[i+1]));
    if(x!=(int)v.size()-1 and x) b.push_back(gcd(v[x-1],v[x+1]));
    for(int i=x+1;i<(int)v.size()-1;i++) b.push_back(gcd(v[i],v[i+1]));

    for(int i=0;i<(int)b.size()-1;i++) if(b[i]>b[i+1]) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), b(n-1);
    for(int &i:v) cin >> i;

    for(int i=0;i<n-1;i++) b[i] = gcd(v[i],v[i+1]);

    int q=0,s=0;
    for(int i=0;i<n-2;i++) {
        if(b[i]>b[i+1]) {
            s++;
            if(s==1) q++;
        } else s=0;
    }
    if(q==0) {
        cout << "YES\n";
        return;
    } else if(q>2) {
        cout << "NO\n";
        return;
    }

    int i;
    for(i=0;i<(int)b.size()-1;i++) if(b[i]>b[i+1]) break;
    
    for(int j=-5;i+j<n and j<10;j++) {
        if(i+j>=0 and brute(v,i+j)) {
            cout << "YES\n";
            return;
        } 
    }

    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
