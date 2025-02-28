#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a?a:get(p,p[a]));
}

void Union(vector<int> &p, vector<int> &r, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(r[a]==r[b]) r[a]++;
    else if(r[b]>r[a]) swap(a,b);
    p[b]=a;
}

int getv(vector<int> &p) {
    for(int i=1;i<(int)p.size();i++) 
        if(get(p,0)!=get(p,i)) return i+1;
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n),r(n,1);
    for(int i=0;i<n;i++) p[i] = i;

    vector<pair<int,int>> edges;

    while(true) {
        int b = getv(p);
        if(b==-1) break;
        int a=1,q;
        while(true) {
            cout << "? " << a << ' ' << b << '\n';
            cout.flush();
            cin >> q;
            if(q==a) {
                edges.push_back(make_pair(a,b));
                Union(p,r,a-1,b-1);
                break;
            } else if(get(p,a-1)==get(p,q-1)) a=q;
            else b=q;
        }
    }

    cout << "! ";
    for(auto &i: edges) cout << i.ff << ' ' << i.ss << ' ';
    cout << '\n';
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
