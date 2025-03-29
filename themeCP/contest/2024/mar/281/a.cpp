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
    
    vector<int> v1(n),v2(n), q1(2*n+1,0), q2(2*n+1,0);
    for(int &i:v1) cin >> i;
    for(int &i:v2) cin >> i;

    int q=1,act=v1[0];
    q1[act]++;
    for(int i=1;i<n;i++) {
        if(v1[i]==act) {
            q++;
            q1[act] = max(q,q1[act]);
        } else {
            q=1;
            act = v1[i];
            q1[act] = max(q,q1[act]);
        }
    }
    
    q=1,act=v2[0];
    q2[act]++;
    for(int i=1;i<n;i++) {
        if(v2[i]==act) {
            q++;
            q2[act] = max(q,q2[act]);
        } else {
            q=1;
            act = v2[i];
            q2[act] = max(q,q2[act]);
        }
    }

    int ans=0;
    n+=n;
    for(int i=0;i<n;) {
        i++;
        ans=max(ans,q1[i]+q2[i]);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
