#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int get(vector<int> &p, int a) {
    return (a==p[a]? a : get(p,p[a]));
}

int getSum(vector<int> &p, vector<int> &s, int a) {
    return s[a] + (a==p[a] ? 0 : getSum(p,s,p[a]));
}

void Union(vector<int> &rank, vector<int> &p, vector<int> &s, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(rank[a]==rank[b]) rank[a]++;
    if(rank[b]>rank[a]) swap(a,b);
    
    p[b] = a;
    s[b]-=getSum(p,s,a);
}

int main() { _
    int n,q,x,y;
    string s;
    cin >> n >> q;

    vector<int> rank(n,1), p(n), sum(n,0);

    for(int i=0;i<n;i++) p[i] = i;

    while(q--) {
        cin >> s >> x;
        x--;

        if(s[0]=='j') {
            cin >> y;
            y--;
            Union(rank,p,sum,x,y);
        } else if(s[0]=='a') {
            cin >> y;
            x = get(p,x);
            sum[x]+=y;
        } else cout << getSum(p,sum,x) << '\n';
    }

    return 0;
}
