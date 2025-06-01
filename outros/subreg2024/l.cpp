#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n), oc(32,0);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        for(int j=0;j<32;j++) if(v[i]&(1<<j)) oc[j]++;
    }

    v.assign(n,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<32;j++) if(oc[j]) {oc[j]--;v[i]|=(1<<j);}
    }

    for(auto i:v) cout << i << ' ';
    cout << '\n';
    
    return 0;
}