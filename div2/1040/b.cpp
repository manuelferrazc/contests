#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void print(vector<int> &v) {
    for(int i:v) cout << i << ' ';
    cout << '\n';
}

void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    int q[3];
    q[0] = q[1] = q[2] = 0;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[i] = x;
        q[x]++;
    }

    if(s==q[1]+2*q[2]) {
        cout << -1 << '\n';
        return;
    }
    s-=q[1]+2*q[2];
    if(s<0) return print(v);
    
    if((q[1]>1 and (s&1)==0) or s%2==0 or s%3==0 or (s>=2 and (s-2)%3==0) or (s>=4 and (s-4)%3==0)) {
        cout << -1 << '\n';
        return;
    }

    for(int i=0;i<n;i++) {
        if(q[0]) v[i] = 0;
        else if(q[2]) v[i] = 2;
        else v[i] = 1;
        q[v[i]]--;
    }

    print(v);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
