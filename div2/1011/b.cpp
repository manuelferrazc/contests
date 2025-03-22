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
    for(int &i:v) cin >> i;
    vector<pair<int,int>> op;
    bool z=true;
    for(int i=0;z and i<n;i++) {
        if(v[i]) z=false;
    }

    if(z) {
        cout << 3 << '\n' << n-1 << ' ' << n << '\n' << 1 << ' ' << n-2 << '\n' << 1 << ' ' << 2 << '\n';
        return;
    }

    if(v.back()==0) {
        v.pop_back();
        v.back() = (v.back()==1?2:1);
        op.push_back({n-1,n});
        n--;
    }
   vector<int> v1;
   for(int i=0;i<n;i++) {
       if(v[i]==0) {
           if(v[i+1]) {
               op.push_back({v1.size()+1,v1.size()+2});
               v1.push_back(v[i+1]==1?2:1);
               i++;
           } else {
                int j=i;
               for(i=i+1;v[i+1]==0;i++) {}
               op.push_back({v1.size()+1,v1.size()+i-j+1});
               v1.push_back(1);
           }
       } else v1.push_back(v[i]);
   }    
       op.push_back({1,v1.size()});

    cout << op.size() << '\n';
    for(auto i:op) cout << i.ff << ' ' << i.ss << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
