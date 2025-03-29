#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll cost=0;
    for(int i=n-1;i>=0;i--) {
        if(i==0) {cout << "1 ";cost+=i+1;}
        if(i and s[i-1]=='1') s[i-1] = '0';
        i--;
        for(;i>=0 and s[i]=='0';i--) {cost+=i+1;cout << i+1 << ' ';}
        if(i<0) break;
        i++;
    }
    
    cout << cost << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
