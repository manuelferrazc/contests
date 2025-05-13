#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n;
    cin >> n;

    ll q2=0,q5=0;

    ll act;
    for(ll i=5;i<=n;i+=5) {
        act = i;
        while(act%5==0) {
            q5++;
            act/=5;
        }
    }

    if(n<1000000) for(ll i=2;i<=n;i+=2) {
        act = i;
        while((act&1)==0) {
            q2++;
            act>>=1;
        }
    } else q2 = INT_MAX;

    cout << min(q2,q5) << '\n';
    
    return 0;
}
