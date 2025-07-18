#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int act = v[k-1];
    sort(v.begin(),v.end());

    // while(v.size()>2 and v.back()==v[v.size()-2]) v.pop_back();
    int id = 0,us=0;
    
    while(v[id]!=v.back()) {
        if(v[id]<act) id++;
        // tempo q precisa pra chegar for > tempo q tenho pra chegar
        else if(v[id+1]-v[id]>v[id]-us) {
            cout << "NO\n";
            return;
        } else {
            us+=v[id+1]-v[id];
            id++;
        }
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
