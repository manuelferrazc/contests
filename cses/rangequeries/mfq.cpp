#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int lim = 1'000'000;
const int log3 = 18;

int main() { _
    int n,q;
    cin >> n >> q;

    vector<pair<int,int>> v(n);
    for(auto &[a,b]:v) {
        cin >> a >> b;
        a--;
        b--;
    }

    n++;
    v.push_back(pair(lim,lim));

    sort(v.begin(),v.end());

    pair<int,int> *end = new pair<int,int>[lim+1];
    for(int i=0;i<=lim;i++) end[i].ff = end[i].ss = INT_MAX;
    
    for(int i=0;i<n;i++) 
        end[v[i].ff] = min(end[v[i].ff],pair(v[i].ss,i));
    
    pair<int,int> *sm = new pair<int,int>[lim+1];
    sm[lim] = end[lim];
    for(int i=lim-1;i>=0;i--) sm[i] = min(sm[i+1],end[i]);
    
    int mat[n][log3];
    for(int i=0;i<log3;i++) mat[n-1][i] = -1;
    for(int i=n-2;i>=0;i--){
        int j=1;
        mat[i][0] = sm[v[i].ss].ss;

        for(;j<log3;j++) {
            int id = mat[mat[i][j-1]][j-1];
            if(id==-1) break;
            mat[i][j] = id;
        }

        for(;j<log3;j++) mat[i][j] = -1;
    }

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        
        int ans = 0;
        int act = sm[l].ss;

        int j = log3-1;
        while(v[act].ss<=r and j>=0) {
            int id = mat[act][j];
            if(id==-1 or v[id].ss>r) {
                j--;
                continue;
            }

            if(j>=0) ans+=1<<j;
            act = id;
        }

        if(v[act].ss<=r) ans++;

        cout << ans << '\n';        
        
    }

    delete[] sm;
    delete[] end;

    return 0;
}
