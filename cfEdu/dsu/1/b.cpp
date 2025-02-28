#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct sla {
    int min;
    int max;
    int p;

    sla(int a=0, int b=0, int c=0) : min(a), max(b), p(c) {}
};

int get(vector<sla> &p, int a) {
    return p[a].p = (p[a].p==a ? a : get(p,p[a].p));
}

void Union(vector<int> &size, vector<sla> &p, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(size[b]>size[a]) swap(a,b);
    p[b].p = a;
    p[a] = sla(min(p[a].min,p[b].min),max(p[a].max,p[b].max),a);
    size[a]+=size[b];
}

int main() { _
    int n,q,a,b;
    string s;
    cin >> n >> q;

    vector<int> size(n,1);
    vector<sla> p(n);

    for(int i=0;i<n;i++) p[i] = sla(i,i,i);

    while(q--) {
        cin >> s >> a;
        a--;
        if(s[0]=='u') {
            cin >> b;
            b--;
            Union(size,p,a,b);
        } else {
            a = get(p,a);
            cout << p[a].min+1 << ' ' << p[a].max+1 << ' ' << size[a] << '\n';
        }
    }

    return 0;
}
