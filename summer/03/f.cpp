#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> fat(int n) {
    vector<pair<int,int>> ret;

    if(n%2==0) {
        int c=0;
        while(n%2==0) {
            c++;
            n>>=1;
        }

        ret.push_back(pair(2,c));
    }

    for(int i=3;i*i<=n;i+=2) {
        int c=0;
        while(n%i==0) {
            c++;
            n/=i;
        }

        if(c) ret.push_back(pair(i,c));
    }

    if(n>1) ret.push_back(pair(n,1));
    return ret;
}

map<int,int> dp;

int ddp(int n) {
    if(dp.count(n)) return dp[n];

    set<int> s;
    for(int i=1;(1<<i)<=n;i++) {
        int mask = (n&((1<<i)-1))|(n>>i);
        s.insert(ddp(mask));
    }

    for(int i=0;;i++) if(not s.count(i)) {
        dp[n] = i;
        break;
    }

    return dp[n];
}

int main() { _
    int n;
    cin >> n;

    map<int,int> m;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        for(auto[a,b]:fat(x)) {
            m[a]|=(1<<b);
        }
    }

    for(auto it = m.begin();it!=m.end();it++) it->ss|=1;

    dp[1] = 0;

    int x=0;
    for(auto [lixo,b]:m) x^=ddp(b);

    if(x) cout << "Mojtaba\n";
    else cout << "Arpa\n";

    return 0;
}