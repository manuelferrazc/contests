#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,m;
    cin >> n >> m;

    vector<string> v(n);
    for(string &s:v) cin >> s;

    vector<int> qtd(n,0);

    for(int t=0;t<m;t++) {
        int x[2];
        x[0] = x[1] = 0;

        for(int i=0;i<n;i++) x[v[i][t]-'0']++;
        int g = x[0]>x[1]? 0 : 1;
        for(int i=0;i<n;i++) if((v[i][t]-'0')!=g) qtd[i]++;
    }

    int mx = *max_element(qtd.begin(),qtd.end());

    for(int i=0;i<n;i++) if(qtd[i]==mx) cout << i+1 << ' ';
    cout << '\n';

    return 0;
}
