#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

bool solve(vector<ll> &p, vector<ll> cap) {
    ull c=0;
    for(ull i=0;i<p.size() and c<cap.size();) {
        if(p[i]<=cap[c]) cap[c]-=p[i++];
        else {c++;if(c==cap.size()) return false;}
    }
    return true;
}

int main() { _
    ll n,m; cin >> n >> m;
    vector<ll> pr(n);
    for(auto &i:pr) cin >> i;
    vector<ll> cap(m);
    for(auto &i: cap) cin >> i;

    sort(pr.begin(),pr.end());

    do {
        if(solve(pr,cap)) {
            cout << "sim\n";
            return 0;
        }
    } while (next_permutation(pr.begin(),pr.end()));

    cout << "nao\n";
    return 0;
}
