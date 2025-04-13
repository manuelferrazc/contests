#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> v,dp;

void sum(int i, int j, int q) {
    while(i<=j) v[i++]+=q;
}

int d(int mask) {
    if(mask==0) return 0;
    if(dp[mask]!=INT_MAX) return dp[mask];
    
    int m = mask,i=0;
    for(;;i++) if(mask&(1<<i)) break;
    int s=i;//,vv=v[i];

    for(;mask&(1<<i) and i<n;i++) {
        if(v[i]==v[s]) m&=~(1<<i);
        dp[mask] = min(dp[mask],1+d(m));
    }
    // cout << mask << ' ' << dp[mask] << '\n';
    return dp[mask];
}

int main() { _
    cin >> n;
    v.resize(n);
    dp.assign(1<<n,INT_MAX);
    for(int &i:v) cin >> i;
    int mm = *min_element(v.begin(),v.end());
    if(*max_element(v.begin(),v.end())==0) {
        cout << "0\n";
        return 0;
    }
    for(int &i:v) i-=mm;
    
    int ans=(mm>0);
    for(int i=0;i<n;i++) {
        if(v[i]) {
            if(i==n-1) {
                ans++;
                break;
            } else if(v[i]==v[i+1]) continue;
            int init=0;
            for(;i<n;i++) {
                if(v[i]==0) {
                    ans+=d(init);
                    break;
                }
                if(i<n-1 and v[i]==v[i+1]) {
                    init|=1<<i;
                    ans+=d(init);
                    while(i<n-1 and v[i]==v[i+1]) i++;
                    break;
                } else if(i and i<n-1 and v[i-1]+v[i+1]==v[i]) {
                    // init|=1<<i;
                    ans+=d(init);
                    break;
                } else if(i==n-1) {
                    init|=1<<i;
                    ans+=d(init);
                    break;
                }
                init|=1<<i;
            }
        }
    }
    // for(int i:v) cout << i << ' ';
    cout << ans << '\n';
    // for(int i=0;i<dp.size();i++) {
        // cout << i << ' ' << dp[i] << '\n';
    // }
    return 0;
}
