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
    
    vector<vector<int>> v(n,vector<int>(n-1));
    for(int i=0;i<n;i++) 
        for(int j=n-2;j>=0;j--) cin >> v[i][j];
    
    while(n--) {
        int x;
        if(not v[0].size()) x=v[1].back();
        else if((not v[1].size()) or not v[2].size()) x=v[0].back();
        else if(v[0].back()==v[1].back() or v[0].back()==v[2].back()) x=v[0].back();
        else x=v[1].back();
        
        cout << x << ' ';
        for(auto &i:v) {
            if(i.size() and i.back()==x) i.pop_back();
        }
    }
    cout << '\n';   
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
