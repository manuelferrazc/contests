#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q,l,r;
    cin >> n >> q;

    int sq = sqrt(n);

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> cnt;

    for(int b=0;b*sq<n;b++) {
        cnt.push_back({});
        cnt[b].push_back(v[b*sq]);
        for(int i=1;i<sq and b*sq+i<n;i++) {
            if(v[i+b*sq]>cnt[b].back()) cnt[b].push_back(v[b*sq+i]);
        }
    }



    while(q--) {
        cin >> l >> r;
        l--;
        r--;

        int ans=0,m=0;

        while(l<n and l<=r and l%sq) {
            if(v[l]>m) {
                ans++;
                m = v[l];
            }
            l++;
        }

        for(int b=l/sq;b*sq<n;b++) {
            // if((b+1)*r)
        }
    }
    
    return 0;
}
