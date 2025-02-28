#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return (p[a]==a ? a : get(p,p[a]));
}

int getS(vector<int> &p, vector<int> &s, int a) {
    if(a==p[a]) return s[a];
    return 1+s[a]+getS(p,s,p[a]);
}

void Union(vector<int> &p, vector<int> &s, vector<int> &r, int a, int b) { // a vira sub de b
    if(r[a]<=r[b]) {
        if(r[a]==r[b]) r[b]++;
        p[a] = b;
    } else {
        int qtd = getS(p,s,b);
        s[a]+=qtd;
        s[b]=1;
    }
}

int main() { _
    int n,m;
    cin >> n >> m;
    

    return 0;
}
