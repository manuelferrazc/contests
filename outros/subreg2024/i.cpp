#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll max = 1'000'000;
const ll mod = 1e9+7;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1 ? r*n%mod : r;
}

vector<int> c(::max+1),where(::max+1,1);

int fatt(vector<int> &fat, int n) {
    int r=1;
    while(n>1) {
        fat.push_back(c[n]);
        r*=c[n];
        n = where[n];
    }
    return r;
}

int main() { _
    iota(c.begin(),c.end(),0);
    for(int i=2;i<=::max;i++) {
        if(c[i]!=i) continue;
        
        for(int j=i+i;j<=::max;j+=i) {
            c[j] = i;
            if((j/i)%i==0) where[j] = where[j/i];
            else where[j] = j/i;
        }
    }

    ll n;
    cin >> n;
    vector<int> v(n);
    vector<int> count(::max+1,0);
    for(int i:v) {
        cin >> v[i];
        count[v[i]]++;
    }

    vector<int> div(::max+1,0);
    for(int i=2;i<=::max;i++) {
        for(int j=i;j<=::max;j+=i) div[i]+=count[j];
    }

    vector<int> qtd(::max+1);
    qtd[0] = qtd[1] = 0;

    for(int i=2;i<=::max;i++) {
        if(c[i]==i) qtd[i] = div[i];
        else {
            vector<int> fat;
            fatt(fat,i);
            qtd[i] = 0;
            for(int mask=1;mask<(1<<fat.size());mask++) {
                int m=0;
                int x=1;
                for(int j=0;j<7;j++) if(mask&(1<<j)) {
                    x*=fat[j];
                    m++;
                }
                if(m&1) qtd[i]+=div[x];
                else qtd[i]-=div[x];
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << fexp(2,n-qtd[x]) << '\n';
    }

    return 0;
}
