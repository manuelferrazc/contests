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
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    if(n==1) {
        cout << "NO\n";
        return;
    }
    set<ll> s;
    s.insert(0);
    ll sum = v[0]-v[1];
    s.insert(sum);
    if(sum==0) {
        cout << "YES\n";
        return;
    } else if(n==2) {
        cout << "NO\n";
        return;
    }

    // começa em par
    for(int i=2;i<n;i+=2) {
        sum+=v[i];
        if(s.count(sum)) {
            cout << "YES\n";
            return;
        }
        if(i!=n-1) sum-=v[i+1];
        else break;
        if(s.count(sum)) {
            cout << "YES\n";
            return;
        }
        s.insert(sum);
    }

    s.clear();
    s.insert(0);
    sum = v[1]-v[2];
    if(sum==0) {
        cout << "YES\n";
        return;
    }
    s.insert(sum);
    // começa em impar
    for(int i=3;i<n;i+=2) {
        sum+=v[i];
        if(s.count(sum)) {
            cout << "YES\n";
            return;
        }
        if(i!=n-1) sum-=v[i+1];
        else break;
        if(s.count(sum)) {
            cout << "YES\n";
            return;
        }
        s.insert(sum);
    }

    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
