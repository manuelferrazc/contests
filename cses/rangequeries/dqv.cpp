#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int compress(int *v, int n) {
    pair<int,int> aux[n];
    for(int i=0;i<n;i++) aux[i] = pair(v[i],i);

    sort(aux,aux+n);
    int c=0;
    v[aux[0].ss] = 0;
    for(int i=1;i<n;i++) {
        if(aux[i-1].ff!=aux[i].ff) c++;
        v[aux[i].ss] = c;
    }

    return c+1;
}

inline void zero(int *v, int n) {
    for(int i=0;i<n;i++) i[v] = 0;
}

int main() { 
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];
    
    int c = compress(v,n);

    
    int cnt[c];
    
    array<int,3> qs[q];
    for(int i=0;i<q;i++) {
        cin >> qs[i][0] >> qs[i][1];
        qs[i][0]--;
        qs[i][1]--;
        qs[i][2] = i;
    }
    
    sort(qs,qs+q);
    
    int ans[q];
    
    int sq = sqrt(n), rv = 0, id = 0;
    vector<array<int,3>> q2;
    
    while(id<q) {
        rv+=sq;
        
        while(id<q and qs[id][0]<rv) {
            q2.push_back(qs[id]);
            id++;
        }
        
        if(q2.empty()) continue;
        sort(q2.rbegin(),q2.rend(),[](array<int,3> const &a1, array<int,3> const &a2) -> bool {
            if(a1[1]<a2[1]) return true;
            return a1[1]==a2[1] and a1[0]<a2[0];
        });
        
        zero(cnt,c);
        int act=0;
        int l = q2.back()[0],r = q2.back()[1];
        
        for(int i=l;i<=r;i++) {
            if(cnt[v[i]]==0) act++;
            cnt[v[i]]++;
        }
        
        ans[q2.back()[2]] = act;
        q2.pop_back();
        
        while(q2.size()) {
            while(r<q2.back()[1]) {
                r++;
                if(cnt[v[r]]==0) act++;
                cnt[v[r]]++;
            }

            while(l<q2.back()[0]) {
                if(cnt[v[l]]==1) act--;
                cnt[v[l]]--;
                l++;
            }

            while(q2.back()[0]<l) {
                l--;
                if(cnt[v[l]]==0) act++;
                cnt[v[l]]++; 
            }

            ans[q2.back()[2]] = act;
            q2.pop_back();
        }
    }

    for(int i=0;i<q;i++) cout << ans[i] << '\n';

    return 0;
}
