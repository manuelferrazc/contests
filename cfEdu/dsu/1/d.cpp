#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct op {
    bool cut = false;
    int u;
    int v;
};

int get(vector<int> &p, int a) {
    return p[a] = (a==p[a] ? a : get(p,p[a]));
}

void Union(vector<int> &p, vector<int> &r, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(r[a]==r[b]) r[a]++;
    if(r[b]>r[a]) p[a] = b;
    else p[b] = a;
}

int main() { _
    int n,m,nOp;
    string s;
    cin >> n >> m >> nOp;

    vector<op> operations(nOp);
    while(m--) cin >> operations[0].u >> operations[0].u;

    while(nOp--) {
        cin >> s >> operations[nOp].u >> operations[nOp].v;
        if(s[0]=='c') operations[nOp].cut = true;
    }

    vector<int> p(n),r(n,1);
    for(int i=0;i<n;i++) p[i] = i;
    vector<bool> ans;

    for(auto &op:operations) {
        op.u--;
        op.v--;
        if(op.cut) Union(p,r,op.u,op.v);
        else ans.push_back(get(p,op.v)==get(p,op.u));
    }

    for(auto it=ans.rbegin();it!=ans.rend();it++) {
        if(*it) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
