#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int m;

bool brute(vector<vector<int>> &v, vector<bool> &ap, vector<int> &ans, int d) {
    if(d==-1) return true;
    vector<int> p;
    for(auto i:v[d]) {
        if(not ap[i-1]) p.push_back(i);
    }
    for(auto i:v[d]) ap[i-1] = true;
    for(auto i:p) {
        ans.push_back(i);
        if(brute(v,ap,ans,d-1)) return true;
        ans.pop_back();
    }
    return false; 
}

void solve() {
    cin >> m;

    vector<vector<int>> v(m);
    int s=0;
    for(int i=0;i<m;i++) {
        int n,x; 
        cin >> n;
        map<int,int> ma;
        for(int j=0;j<n;j++) {
            cin >> x;
            s=max(s,x);
            ma[x]++;
        }
        for(auto j:ma) if(j.ss==1) v[i].push_back(j.ff);
    }

    vector<bool> ganhou(s,false);
    vector<int> ans;

    if(brute(v,ganhou,ans,m-1)) {
        for(auto i=ans.rbegin();i!=ans.rend();i++) cout << *i << ' ';
        cout << '\n';
    } else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
