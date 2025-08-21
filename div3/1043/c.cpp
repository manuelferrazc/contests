#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> p;


ll solve() {
    ll n,k;
    cin >> n >> k;
    if(n<=k) return 3*n;
    ll sum=0,qtd=0;
    ll val=0;
    multiset<pair<ll,ll>> ans;
    while(sum<n) {
        if(qtd==k) return -1;
        auto it = upper_bound(p.begin(),p.end(),n-sum);
        it--;
        qtd++;
        ll pos = it-p.begin();
        ans.insert({*it,pos});
        sum+=*it;
        val+=p[pos+1]+(pos?pos*p[pos-1]:0);
    }

    while(qtd+2<=k) {
        auto it = ans.end();
        it--;
        if(it->ss==0) break;
        qtd+=2;

        ll pos = it->ss;
        val -= p[pos+1]+(pos?pos*p[pos-1]:0);
        pos--;
        val+= 3*(p[pos+1]+(pos?pos*p[pos-1]:0));

        ans.erase(it);
        ans.insert({p[pos],pos});
        ans.insert({p[pos],pos});
        ans.insert({p[pos],pos});
    }

    return val;
}

int main() { 
    p.push_back(1);
    while(p.back()*3<=1e10) p.push_back(p.back()*3);
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
