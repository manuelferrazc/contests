#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,k;
    cin >> n;

    multiset<ll> s[4];

    vector<ll> dp(10,0);
    
    for(int i=0;i<n;i++) {
        s[1].clear();
        s[2].clear();
        s[3].clear();
        cin >> k;
        for(int i=0;i<k;i++) {
            ll c,d;
            cin >> c >> d;
            s[c].insert(d);
        }

        vector<ll> act = dp;
        for(int q=0;q<10;q++) {
            // jogando só 1
            if(dp[q]==0 and q) continue;
            if(q==9) {
                if(s[1].size()) act[0] = max(act[0],dp[q]+2**s[1].rbegin());
                if(s[2].size()) act[0] = max(act[0],dp[q]+2**s[2].rbegin());
                if(s[3].size()) act[0] = max(act[0],dp[q]+2**s[3].rbegin());
            } else {
                if(s[1].size()) act[q+1] = max(act[q+1],dp[q]+*s[1].rbegin());
                if(s[2].size()) act[q+1] = max(act[q+1],dp[q]+*s[2].rbegin());
                if(s[3].size()) act[q+1] = max(act[q+1],dp[q]+*s[3].rbegin());
            }

            // jogando 2
            if(q>=8) {
                // pegando duas de peso 1
                if(s[1].size()>=2) act[(q+2)%10] = max(act[(q+2)%10],dp[q]+2**s[1].rbegin()+*next(s[1].rbegin()));
                // pegando uma de peso 1 e uma de peso 2
                if(s[1].size() and s[2].size()) act[(q+2)%10] = max(act[(q+2)%10],dp[q]+2*max(*s[1].rbegin(),*s[2].rbegin())+min(*s[1].rbegin(),*s[2].rbegin()));
            } else {
                // pegando duas de peso 1
                if(s[1].size()>=2) act[q+2] = max(act[q+2],dp[q]+*s[1].rbegin()+*next(s[1].rbegin()));
                // pegando uma de peso 1 e uma de peso 2
                if(s[1].size() and s[2].size()) act[q+2] = max(act[q+2],dp[q]+*s[1].rbegin()+*s[2].rbegin());
            }

            // jogando 3
            if(q>=7) {
                if(s[1].size()>=3) act[(q+3)%10] = max(act[(q+3)%10],dp[q]+2**s[1].rbegin()+*next(s[1].rbegin())+*next(next(s[1].rbegin())));
            } else {
                if(s[1].size()>=3) act[q+3] = max(act[q+3],dp[q]+*s[1].rbegin()+*next(s[1].rbegin())+*next(next(s[1].rbegin())));
            }
        }
        dp = act;
    }

    cout << *max_element(dp.begin(),dp.end()) << '\n';

    return 0;
}