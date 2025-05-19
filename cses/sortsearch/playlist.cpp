#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    set<int> s;
    int n,ans=0,a=0,b=0;
    cin >> n;

    vector<int> v(n);
    for(int &i:v) cin >> i;

    for(;b<n;b++) {
        while(s.count(v[b])) s.erase(v[a++]);
        s.insert(v[b]);
        ans = max(ans,b-a+1);
    }

    cout << ans << '\n';

    return 0;
}
