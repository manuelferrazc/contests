#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void Union(vector<vector<int>> &v, vector<int> &size, vector<int> &l, int a, int b) {
    a = l[a];
    b = l[b];
    if(a==b) return;

    if(size[b]>size[a]) swap(a,b);
    size[a]+=size[b];

    for(auto i:v[b]) {
        v[a].push_back(i);
        l[i] = a;
    }

    v[b].clear();
}

int main() { _
    int n,q,a,b;
    string s;
    cin >> n >> q;

    vector<int> size(n,1);
    vector<int> l(n);
    vector<vector<int>> v(n,vector<int>(1));

    for(int i=0;i<n;i++) {
        l[i] = i;
        v[i][0] = i;
    }

    while(q--) {
        cin >> s >> a >> b;
        a--;
        b--;
        if(s[0]=='u') Union(v,size,l,a,b);
        else if(l[a]==l[b]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
