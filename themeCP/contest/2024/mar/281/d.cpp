#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool t(string &s,int n, int k) {
    set<int> dis;
    for(int i=n-1,kk=k;i>=0 and kk;i--) {
        if(s[i]=='1') {
            kk--;
            dis.insert(i+1);
        }
    }
    if(dis.size()<k) return false;
    vector<int> ndis;
    for(int i=1;i<=n;i++) if(not dis.count(i)) ndis.push_back(i);

    for(auto i = dis.rbegin();i!=dis.rend();i++) {
        while(ndis.size() and ndis.back()>*i) ndis.pop_back();

        if(ndis.empty()) return false;
        ndis.pop_back();
    }

    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll cost=((1LL+n)*n)>>1;
    
    int l=0,r=n,ans=0;
    while(l<=r) {
        int m = (l+r)>>1;
        if(t(s,n,m)) {
            ans = m;
            l=m+1;
        } else r=m-1;
    }

    for(int i=n-1;ans;i--) {
        if(s[i]=='1') {
            cost-=i+1;
            ans--;
        }
    }
    
    cout << cost << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
