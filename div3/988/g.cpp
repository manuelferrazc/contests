#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 1'000'000
const ll mod = 998'244'353;

vector<int> fat(MAX+1,1);
vector<int> primes_fat(MAX+1,1);

void get_primes(vector<int> &s, int x) {
    while(x>1) {
        int f = primes_fat[x];
        s.push_back(f);
        while(x%f==0) x/=f;
    }
}

int main() { 

    for(int i=2;i<=MAX;i++) {
        if(fat[i]!=1) continue;
        fat[i] = i;
        primes_fat[i] = i;
        for(int j=i+i;j<=MAX;j+=i) {
            fat[j] *= i;
            primes_fat[j] = i;
        }
    }

    int n;
    cin >> n;

    vector<int> dp(MAX+1,0);
    int x,start;
    cin >> start;
    start = fat[start];
    
    vector<int> f;

    for(int i=1;i<n-1;i++) {
        f.clear();

        cin >> x;
        x = fat[x];

        get_primes(f,x);
        ll ans = 0;

        for(int i=1;i<(1<<f.size());i++) {
            int v = 1,qtd=0;
            for(int j=0;j<f.size();j++) if(i&(1<<j)) {
                v*=f[j];
                qtd++;
            }
            if(qtd&1) ans+=dp[v];
            else ans-=dp[v];

            ans = (ans+mod)%mod;
        }

        if(gcd(x,start)>1) ans = (ans+1)%mod;

        for(int i=1;i<(1<<f.size());i++) {
            int v = 1;
            for(int j=0;j<f.size();j++) if(i&(1<<j)) v*=f[j];

            dp[v] = (dp[v]+ans)%mod;
        }
    }

    ll ans = 0;

    int end;
    cin >> end;
    end = fat[end];

    f.clear();
    get_primes(f,end);
    if(gcd(start,end)>1) ans++;

    for(int i=1;i<(1<<f.size());i++) {
        int v = 1,qtd=0;
        for(int j=0;j<f.size();j++) if(i&(1<<j)) {
            v*=f[j];
            qtd++;
        }
        if(qtd&1) ans+=dp[v];
        else ans-=dp[v];

        ans = (ans+mod)%mod;
    }

    cout << ans << '\n';

    return 0;
}
