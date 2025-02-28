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
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    if(n&1) {
        cout << "nO\n";
        return;
    }
    
    sort(v.begin(),v.end());
    vector<int> v1,v2;
    for(int i=0;i<n-i-1;i++) {
        v1.push_back(v[i]);
        v2.push_back(v[n-i-1]);
    }
    v.clear();
    for(auto i:v1) {
        v.push_back(i);
        v.push_back(v2.back());
        v2.pop_back();
    }
    for(int i=0;i<n;i++) {
        if((v[i]>v[(i+1)%n] and v[i]>v[(i-1+n)%n]) or (v[i]<v[(i+1)%n] and v[i]<v[(i-1+n)%n])) continue;
        else {
            cout << "no\n";
            return;
        }
    }
    cout << "yEs\n";
    for(auto i:v) cout << i << ' '; 
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
