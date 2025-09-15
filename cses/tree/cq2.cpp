#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int getKA(vector<vector<int>> const &ka, const int l, int a, int k) {
    for(int i=0;i<l;i++) if(k&(1<<i)) a = ka[a][i];
    return a;
}

int getLCA(vector<vector<int>> const &ka, vector<int> const &p, const int l, int a, int b) {
    if(p[a]<p[b]) swap(a,b);
    if(p[a]!=p[b]) a = getKA(ka,l,a,p[a]-p[b]);
    if(a==b) return a;
    
    for(int i=l-1;i>=0;i--) {
        if(ka[a][i]!=ka[b][i]) {
            a = ka[a][i];
            b = ka[b][i];
        }
        // cout << a+1 << ' ' << b+1 << '\n';
    }

    return ka[a][0];
}

int main() { 
    int n,q;
    cin >> n >> q;

    int l=0;
    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;

    vector<int> p(n);
    vector<vector<int>> ka(n,vector<int>(l,-1));
    p[0] = 0;

    for(int i=1;i<n;i++) {
        int c;
        cin >> c;
        ka[i][0] = c-1;
        p[i] = p[c-1]+1;

        for(int j=1;j<l;j++) if(ka[i][j-1]!=-1) ka[i][j] = ka[ka[i][j-1]][j-1];
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<l;j++) cout << ka[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    while(q--) {
        int a,b;
        cin >> a >> b;
        cout << getLCA(ka,p,l,a-1,b-1)+1 << '\n';
    }

    // cout << '\n' << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout << i+1 << ' ' << j+1 << ' ' << getLCA(ka,p,l,i,j)+1 << '\n';
    //     }
    // }

    return 0;
}
