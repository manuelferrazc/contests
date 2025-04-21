#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int median(ordered_set &s) {
    if(s.size()&1) return *s.find_by_order(s.size()>>1);
    return *s.find_by_order((s.size()>>1)-1);
}

bool check1(vector<ll> &v, ll k) {
    ll i=1,j;

    ll qk=0,qm=0;
    if(v[0]>k) qm++;
    else qk++;
    for(i=1;qk<qm and i<v.size();i++) {
        if(v[i]<=k) qk++;
        else qm++;
    }
    if(qk<qm) return false;
    
    qk=0;
    qm=0;
    j=v.size()-2;
    if(v.back()<=k) qk++;
    else qm++;
    
    for(;qk<qm and j>=0;j--) {
        if(v[j]<=k) qk++;
        else qm++;
    }
    // cout << qm << ' ' << qk << '\n';
    if(qm>qk) return false;
    if(i>j) return false;
    return true;
}

bool check2(vector<ll> &v, ll k) {
    ll i=1;

    ll qk=0,qm=0;
    if(v[0]>k) qm++;
    else qk++;
    for(i=1;qk<qm and i<v.size()-2;i++) {
        if(v[i]<=k) qk++;
        else qm++;
    }
    if(qk<qm) return false;
    if(qk>qm and v[i]>k) i++;
    // cout << qk << ' ' << qm << ' ';
    qk=0;
    qm=0;
    if(v[i]<=k) qk++;
    else qm++;
    // cout << "number\n";
    for(i++;qk<qm and i<v.size();i++) {
        // cout << v[i] << '\n';
        if(v[i]<=k) qk++;
        else qm++;
        // cout << qk << ' ' << qm << '\n';
    }
    // cout << qk << ' ' << qm << '\n';
    return qk>=qm and i<v.size();
}

void solve() {
    ll n,k;
    cin >> n >> k;

    vector<ll> v(n),p(n),s(n);
    for(ll &i:v) cin >> i;

    if(check1(v,k)) cout << "YES\n";
    else if(check2(v,k)) cout << "YES\n";
    else {
        reverse(v.begin(),v.end());
        if(check2(v,k)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
