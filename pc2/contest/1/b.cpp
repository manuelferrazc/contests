#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,k;
    cin >> n >> k;

    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int ans=INT_MAX;

    vector<int> perm(k);
    iota(perm.begin(),perm.end(),0);

    vector<string> v2 = v;
    do {
        set<int> s;
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) v2[i][j] = v[i][perm[j]];
            s.insert(stoi(v2[i]));
        }
        ans = min(ans,*s.rbegin()-*s.begin());
    } while(next_permutation(perm.begin(),perm.end()));

    cout << ans << '\n';
    return 0;
}
