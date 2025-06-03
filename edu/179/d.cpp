#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;

    map<int,vector<int>> a;
    for(int i=0;i<m;i++) {
        int s;
        cin >> s;
        a[s/100].push_back(s);
    }

    auto b = a;

    vector<int> d1(n),d2(n);
    for(int i=0;i<n;i+=2) {
        auto it = a.begin();
        auto it2 = b.rbegin();
        d1[i] = it->ss.back();
        it->ss.pop_back();
        if(it->ss.empty()) a.erase(it->ff);
        d2[i] = it2->ss.back();
        it2->ss.pop_back();
        if(it2->ss.empty()) b.erase(it2->ff);
    }

    for(int i=1;i<n;i+=2) {
        auto it = a.rbegin();
        auto it2 = b.begin();
        d1[i] = it->ss.back();
        it->ss.pop_back();
        if(it->ss.empty()) a.erase(it->ff);
        d2[i] = it2->ss.back();
        it2->ss.pop_back();
        if(it2->ss.empty()) b.erase(it2->ff);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) cout << d1[i] << ' ' << d2[i] << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
