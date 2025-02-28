#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool s(int a, int b, int c) {
    return (a+b)>c and (a+c)>b and (b+c)>a;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int c=0;
    // for(int i=0;i<n-2;i++) if(s(v[i],v[i+1],v[i+2])) c++;
    for(int i=0;i<n-1;i++) if(s(v[i],v[i],v[i+1]) and s(v[i],v[i+1],v[i+1])) c++;

    if(c>=1) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
