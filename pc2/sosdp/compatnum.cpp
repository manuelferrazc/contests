#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    const int p = (1<<22)-1;
    
    int n;
    cin >> n;
    
    int v[n];
    vector<int> oc(p+1,-1);
    
    for(int i=0;i<n;i++) {
        cin >> v[i];
        oc[v[i]] = v[i];
    }   

    int *dp;
    dp = new int[p+1];
    for(int i=0;i<=p;i++) dp[i] = oc[i];
    
    for(int x=0;x<=p;x++) {
        for(int i=0;i<22;i++) {
            if((x&(1<<i)) and dp[x]==-1) {
                dp[x] = dp[x^(1<<i)];
            }
        }
    }

    for(int i=0;i<n;i++) {
        int neg = p-v[i];

        cout << dp[neg] << ' ';
    }

    cout << '\n';

    delete[] dp;

    return 0;
}
