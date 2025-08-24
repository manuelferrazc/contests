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

void unionn(vector<int> &p, vector<int> &s, vector<int> &black, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(s[a]<s[b]) swap(a,b);
    s[a]+=s[b];
    black[a]+=black[b];
    p[b] = a;
}

int main() { _
    int n,q;
    cin >> n >> q;

    vector<int> p(n), s(n,1), black(n,0), color(n,0);
    iota(p.begin(),p.end(),0);

    int op,a,b;
    while(q--) {
        cin >> op >> a;
        a--;
        
        if(op==1) {
            cin >> b;
            unionn(p,s,black,a,b-1);
        } else if(op==2) {
            int rep = get(p,a);
            if(color[a]==0) black[rep]++;
            else black[rep]--;

            color[a]^=1;
        } else {
            int rep = get(p,a);
            if(black[rep]) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}
