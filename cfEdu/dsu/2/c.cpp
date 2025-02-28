#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a ? a : get(p,p[a]));
}

void UnionDir(vector<int> &p, int a, int b) {
    p[a] = get(p,b);
}

void Union(vector<int> &p, vector<int> &r, int a, int b) {
    a = get(p,a);
    b = get(p,b);

    if(a==b) return;
    if(r[a]==r[b]) r[a]++;
    if(r[b]>r[a]) swap(a,b);

    p[b] = a;
}

int main() { _
    int n,q;
    cin >> n >> q;
    vector<int> p(n), dir(n), r(n,1);
    for(int i=0;i<n;i++) p[i]=dir[i]=i;

    int op,x,y;
    while(q--) {
        cin >> op >> x >> y;
        x--;
        y--;

        if(op==1) Union(p,r,x,y);
        else if(op==2) {
            for(int i=x;i<y;) {
                Union(p,r,i,i+1);
                UnionDir(dir,i,i+1);
                i = get(dir,i);
            }
        } else if(get(p,x)==get(p,y)) cout << "YES\n";
        else cout << "NO\n";
    }
    

    return 0;
}
