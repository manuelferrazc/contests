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
    vector<int> a(n),b(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    vector<pair<int,int>> ans;

    for(int i=0;i<n;i++) {
        if(a[i]>b[i]) {
            swap(a[i],b[i]);
            ans.push_back(make_pair(3,i+1));
        }
    }

    for(int i=0;i<n-1;i++) {
        int j=i;
        while(j>=0 and a[j]>a[j+1]) {
            swap(a[j],a[j+1]);
            ans.push_back(make_pair(1,j+1));
            j--;
        }

        j=i;
        while(j>=0 and b[j]>b[j+1]) {
            swap(b[j],b[j+1]);
            ans.push_back(make_pair(2,j+1));
            j--;
        }
    }

    // for(int i=0;i<n;i++) cout << a[i] << ' ';
    // cout << '\n';
    // for(int i=0;i<n;i++) cout << b[i] << ' ';
    // cout << '\n';

    for(int i=0;i<n;i++) {
        if(a[i]>b[i]) {
            swap(a[i],b[i]);
            ans.push_back(make_pair(3,i+1));
        }
    }

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i.ff << ' ' << i.ss << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
