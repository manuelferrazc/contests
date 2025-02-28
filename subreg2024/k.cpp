#include <bits/stdc++.h>

using namespace std;
#define ff first
#define ss second

pair<int,bool> ddp(vector<vector<pair<int,bool>>> &dp,vector<int> &v, int i, int j) {
    if(dp[i][j].ff!=-1) return dp[i][j];
    if(i==0) return dp[i][j] = {0,0};
    if(j==0) return dp[i][j] = {0,0};

    if(v[i]<=j) {
        auto pu = ddp(dp,v,i-1,j-v[i]);
        pu.ff += v[i];
        auto pn = ddp(dp,v,i-1,j);

        if(pu.ff > pn.ff) return (dp[i][j] = {pu.ff,true});
        else return (dp[i][j] = {pn.ff,false});
    } else return (dp[i][j] = {ddp(dp,v,i-1,j).ff,false});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = 0;
    const int s = accumulate(v.begin()+1,v.end(),0);
    if(s&1) {
        cout << "-1\n";
        return 0;
    }
    const int ms = s/2;

    vector<vector<pair<int,bool>>> dp(n+1,vector<pair<int,bool>>(ms+1,{-1,0}));
    auto r = ddp(dp,v,n,ms);

    if(r.ff<ms) {
        cout << "-1\n";
        return 0;
    }

    set<int> al,bo;

    int i=n,cap = ms;

    while(cap) {
        if(dp[i][cap].ss) {
            cap-=v[i];
            al.insert(i);
        }
        i--;
    }
    for(int i=1;i<=n;i++) if(al.count(i)==0) bo.insert(i);

    int alice = 0, bob = 0;
    vector<int> out;
    while(al.size() or bo.size()) {
        if(alice<=bob) {
            out.push_back(v[(*al.begin())]);
            alice += v[*al.begin()];
            al.erase(al.begin());
        } else {
            out.push_back(v[(*bo.begin())]);
            bob += v[*bo.begin()];
            bo.erase(bo.begin());
        }
    }

    
    for(auto i:out) cout << i << ' ';
    cout << '\n';

    return 0;
}