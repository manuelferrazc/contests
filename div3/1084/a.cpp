#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> ans(n,0);

    for(int s=0;s<n;s++) {
        int g = n;
        vector<int> v2 = v;
        for(int i=s;;i = (i+1)%n) {
            if(v2[i]==0) continue;
            v2[i]--;
            if(v2[i]==0) {
                g--;
                if(g==0) {
                    ans[i] = 1;
                    break;
                }
            }
        }
    }

    cout << accumulate(ans.begin(),ans.end(),0) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
