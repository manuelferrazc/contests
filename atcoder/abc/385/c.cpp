#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    int ans = 1,m;
    for(int i=0;i<n;i++) {
        for(int s = i+1;s<n;s++) {
            if(v[i]!=v[s]) continue;
            m = 2;
            for(int j=2*s-i;j<n and v[j]==v[i];j+=s-i) {
                m++;
            }
            ans = max(ans,m);
        }
    }
    cout << ans << '\n';

    return 0;
}
