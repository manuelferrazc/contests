#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int mod = 998'244'353;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() { _
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dp(n,0);
    dp.back()=1;

    for(int i=0;i<n;i++) cin >> v[i];

    for(int i = n-2;i>=0;i--) 
        for(int j=i+1;j<n;j++) 
            if(gcd(v[i],v[j])!=1) dp[i] = (dp[i]+dp[j])%mod;


    cout << dp.front() << endl;

    return 0;
}
