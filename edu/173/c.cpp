#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool b(ll n, ll d) {
    if(n==1) return false;
    else if(n>=2) {
        if(d%7==0 or (d*10+d)%7==0) return true;
        if(n>=3) {
            if((d*100+d*10+d)%7==0) return true;
            if((d*1000+d*100+d*10+d)%7==0) return true;
            if((d*10000+d*1000+d*100+d*10+d)%7==0) return true;
            if((d*100000+d*10000+d*1000+d*100+d*10+d)%7==0) return true;
            if(n>3) return (d*1'000'000+d*100'000+d*10'000+d*1'000+d*100+d*10+d)%7==0;
        }
    } return false;
}

void solve() {
    ll d,n;
    cin >> n >> d;
    cout << "1 ";
    if(d%3LL==0LL or n>=3LL) cout << "3 ";
    if(d==5LL or d==0LL) cout << "5 ";
    if(d==0LL or d==7LL or b(n,d)) cout << "7 ";
    if(d==0LL or d==9LL or ((d==2 or d==4 or d==1 or d==5 or d==7 or d==8) and n>=6) or ((d==3 or d==6) and n>=3)) cout << "9 ";
    cout << "\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
