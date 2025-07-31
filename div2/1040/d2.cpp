#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int ans,n;
vector<int> v(5001);
vector<int> a(5001);
vector<int> ans2;

void calc() {
    int r=0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(a[i]>a[j]) r++;
    ans=min(ans,r);
    // if(ans>r) ans2 = a,ans=r;
    // if(5==r) {
    //     for(int i=0;i<n;i++) cout << a[i] << ' ';
    //     cout << "\n";
    // }
}

void brute(int i) {
    if(i==n) return calc();

    a[i] = v[i];
    brute(i+1);
    a[i] = 2*n-v[i];
    brute(i+1);
}

void solve() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    ans = INT_MAX;

    brute(0);

    cout << ans << '\n';
    // for(int i=0;i<n;i++) cout << ans2[i] << ' ';
    // cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
